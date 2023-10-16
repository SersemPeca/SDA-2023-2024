
#include <vector>

using namespace std;

// Problem:
// https://leetcode.com/problems/global-and-local-inversions/
class Solution {

public:

    int mergeSortCountInversion(vector<int>& arr,vector<int>& temp,int l, int r) {

        if (l >= r) {
            return 0;
        }

        long long count = 0;

        int mid = (l + r) / 2;
        count += mergeSortCountInversion(arr, temp, l, mid);
        count += mergeSortCountInversion(arr, temp, mid + 1, r);
        count += merge(arr, temp, l, mid + 1, r);

        return count;

    }

    int merge(vector<int>& arr, vector<int>& temp, int l, int mid, int r) {
        long long counter = 0;

        int p1 = l;
        int p2 = mid;
        int k = l;

        while (p1 < mid && p2 <= r) {

            if (arr[p1] > arr[p2]) {
                temp[k++] = arr[p2++];
                counter += mid- p1;
            }

            else {
                temp[k++] = arr[p1++];
            }


        }
        
        while (p1 < mid) {
            temp[k++] = arr[p1++];
        }

        while (p2 <= r) {
            temp[k++] = arr[p2++];
        }

        for (int i = l; i <= r; i++) {
            arr[i] = temp[i];
        }
        
        return counter;
    }

    bool isIdealPermutation(vector<int>& nums) {
        
        long long global, local = 0;

        for (int i = 0; i < nums.size() - 1; i++){
            if (nums[i] > nums[i+1])
                local++;
        }

        vector<int> temp(nums.size());
        global = mergeSortCountInversion(nums, temp, 0, nums.size() - 1);

        return global == local;
    }
};
