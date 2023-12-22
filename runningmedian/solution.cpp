#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <queue>

using namespace std;

#define ll long long

int main() {
    
    priority_queue<ll, vector<ll>, greater<ll>> left;
    priority_queue<ll> right;
    
    int N; cin >> N;
    
    std::cout << std::fixed;
    std::cout << std::setprecision(1);
    
    // We will store the median in left pq when even
    for (int i = 1; i < N + 1; i++) {
        ll num; cin >> num;
        if (left.empty() && right.empty()) {
            left.push(num);
            cout << (double) num << '\n';
            continue;
        }
        
        if (num <= left.top()) {
            right.push(num);
           if (right.size() - left.size() >= 1) {
               ll temp = right.top();
               right.pop();
               left.push(temp);
           }
        }
        
        else {
            left.push(num);
            if (left.size() - right.size() >= 2) {
                ll temp = left.top();
                left.pop();
                right.push(temp);
            }
        }
        if (i % 2 == 0)
            cout << (double) (left.top() + right.top()) / 2 << '\n';
        else
            cout << (double) left.top() << '\n';
        
    }
    
    
    return 0;
}
