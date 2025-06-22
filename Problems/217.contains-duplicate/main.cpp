/*
 * @lc app=leetcode id=217 lang=cpp
 *
 * [217] Contains Duplicate
 */

// @lc code=start
#include <unordered_set>
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seenSet;
        for(int num: nums) {
            if (seenSet.count(num))
                return true;
            seenSet.insert(num);
        } 
        return false;
    }
};
// @lc code=end

