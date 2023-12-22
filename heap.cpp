#include <iostream>
#include <math.h>
#include <queue>
#include <algorithm>
using namespace std;

#define PII pair<int, int>

struct Compare {
    bool operator()(PII& p1, PII& p2) {
        return sqrt(p1.first * p1.first + p1.second * p1.second)
            > sqrt(p2.first * p2.first + p2.second * p2.second);
    } 
};


int main() {

    // 1 := Kakvo da pazim
    // 2 := Kakvo da pazim, v kakvo da go pazim, kak da go pazim
    //std::priority_queue<pair<int, int>> pq;

    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;

    int N, K;
    cin >> N >> K;

    while(N--) {
        PII point;
        cin >> point.first >> point.second;

        pq.push(point);

    }


    while(K--) {
        cout << pq.top().first << ' ' << pq.top().second << '\n';
        pq.pop();
    }

}
