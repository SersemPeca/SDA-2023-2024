/*
 * Problem statement:
 * https://leetcode.com/problems/two-sum/
*/

#include <iostream>
#include <vector>

// pair<T, S>
#include <utility>

using namespace std;

#define VVI vector<vector<int>>
#define PI vector<pair<int, int>>

/*
 * Performs "union" of 2 (disjoint) arrays
 *
 * Does this method worsen our complexity ?
 * Should we get rid of it ?
 */
void insert_indices(vector<int>& fst, vector<int>& snd, vector<int>& res) {
    for(int i: fst) res.push_back(i);
    for(int i: snd) res.push_back(i);
}

/*
 * 
 * Only works if forall i : arr[i] >= 0
 *
 * How would we go about modifying the algorithm to work
 * with negative entries ?
 *
 * What if arr[i] is large (Larger than 10^5 - 1) ?
 * What can we do about it ?
 */
vector<int> twoSum(vector<int>& arr, int k) {
    // occ -> occurances
    VVI occ(1e5);
    vector<int> res;

    for (int i = 0; i < arr.size(); i++)
        occ[arr[i]].emplace_back(i);

    for (int i = 0; i < occ.size(); i++) {
        // Don't look back, only forward
        if (k - i > i && !occ[k - i].empty()) {
            insert_indices(occ[i], occ[k - i], res);
        }

        else if (k - i == i) {
            vector<int> dummy;
            
            // Dont insert if only 1 occurance is to be seen
            if (occ[i].size() != 1)
                insert_indices(occ[i], dummy, res);
        }
    }
    return res;
}
