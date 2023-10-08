#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

int main() {

    int k = 4;
    vector<int> arr = {2, 2, 1, 2, 1, 3, 3, 2};

    // forall i : arr[i] < 500

    int counter = 0;
    
    //O(N)
    vector<int> new_arr(500);
    int size = new_arr.size();
    for (int i = 0; i < arr.size(); i++) {
        new_arr[arr[i]]++;
    }

    for (int i = 0; i <= new_arr.size(); i++) {
        // i - number
        // new_arr[i] - # of times we see i in arr
        if (k - i > i) {
            counter += new_arr[i] * new_arr[k - i];
        }

        else if (k - i == i) {
            counter += (new_arr[i] * (new_arr[i] - 1)) / 2;
        }

    }


    // O(N^2)
    //for (int i = 0; i < arr.size() - 1; i++) {
    //    for (int j = i + 1; j < arr.size(); j++) {

    //        counter = (arr[i] + arr[j] == k) ? counter + 1 : counter;
    //    }
    //}

    //for (int i = 0; i < arr.size(); i++) cout << arr[i] << ' ';
    cout << counter; 

    return 0;
}
