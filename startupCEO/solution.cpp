#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

#define VI vector<int>
#define ll long long

bool check(VI& arr, int target, int counter) {

    int local_counter = 1;
    int curr_sum = 0;
    for (int i = 0; i < arr.size(); i++) {
        curr_sum += arr[i];

        if (curr_sum > target) {
            local_counter++;
            curr_sum = arr[i];
        }

    }

    return local_counter <= counter;

}

int main() {
    int N, T;
    cin >> N >> T;

    VI arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    //sort(arr.begin(), arr.end(), std::greater<int>());

     ll l = 1, r = LLONG_MAX;

    while (l < r) {
        ll mid = l + (r - l) / 2;

        if (check(arr, mid, T)) {
            r = mid - 1;
        }

        else {
            l = mid + 1;
        }
    }

    cout << l;

    return 0;
}
