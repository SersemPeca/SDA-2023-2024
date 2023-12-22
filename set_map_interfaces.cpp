#include <algorithm>
#include <iostream>
#include <optional>
#include <vector>
#include <set>
#include <map>

#define SI set<int>

using namespace std;

int querySet(SI& s) {

    // Middle element


    int ans = lower_bound(s.begin(), s.end(), );
}

int main() {

    // Left := Numbers left of median
    // Right := Numbers right of median
    // Greatest elem in left is median
    set<int> left, right;


    int N; cin >> N;

    int opcode, num;
    for (int i = 0; i < N; i++) {
        // Add
        if (opcode == 1) {
            cin >> num;
            if (num > *(--left.end())) {
                right.insert(num);
                if (right.size() - left.size() > 2) {
                    left.insert(*right.begin());
                    right.erase(right.begin());
                }
            }
        }
    }

}
