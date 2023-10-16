#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;

// Problem:
// https://leetcode.com/problems/3sum/description/
class Solution {


public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // 2 Pointer
        //
        //O(n^2)
        /*
         * Idea:
         * Sort the array
         * ∀i < nums.size() do:
         * 1. Initialize 2 "pointers" (j and k) on both sides of array
         * 2. Check nums[i] + nums[j] + nums[k] = x
         *  2.1 If x < 0, then move left "pointer" to the right
         *  2.2 If x > 0, then move right "pointer" to the left
         *  2.3 If x == 0, then return triplet
         */

        sort(nums.begin(), nums.end());
        
        set<vector<int>> triplets{};

        int l, r, x; 
        for (auto i = 0; i < nums.size(); ++i) {
            l = 0;
            r = nums.size() - 1;
            while (l != r) {
                if (i == l || i == r) {
                    break;
                }

                x = nums[l] + nums[i] + nums[r];

                if (x == 0) {
                    triplets.insert({nums[l], nums[i], nums[r]});
                    ++l;
                    --r;
                } else if (x < 0) {
                    ++l;
                } else if (x > 0) {
                    --r;
                }
            }
        }

        return vector<vector<int>>(triplets.cbegin(), triplets.cend());
    }

    // O(n^2)
    // Idea:
    // 1. Reduce the complexity from O(n^3) to O(n^2) by first iterating through and saving arr[i] + arr[j] for i < j
    // 2. Afterwards loop through array and check if a number equal to -(arr[i] + arr[j]) exists.
    //
    // This solution however, as it stands, will produce repeating entries.
    // Think about how we can avoid this problem.
    // Can we maybe store triples we've seen (hash them) ?
    //
    // Proposed by: <placeholder>
    //
    vector<vector<int>> threeSumV2(vector<int>& nums) {

        sort( nums.begin(), nums.end() );
        nums.erase( unique( nums.begin(), nums.end() ), nums.end() );

        unordered_map<int, vector<int>> m;
        int size = nums.size();


        for (int i = 0; i < size; i++) {
            for (int j = i + 1; j < size; j++) {
                int index = nums[i] + nums[j];
                m.insert({index, {nums[i], nums[j]}});
            }
        }

        vector<vector<int>> ans;
        for (int i = 0; i < size; i++) {
            if (m.find(-nums[i]) != m.end()) {
                vector<int> entry = m.find(-nums[i])->second;
                entry.push_back(nums[i]);
                ans.push_back(entry);
            }
        }

        return ans;

    }

};
