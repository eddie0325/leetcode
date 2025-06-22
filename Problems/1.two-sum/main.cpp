/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> indexMap;
        for(int i = 0; i < nums.size(); i++) {
            int partner = target - nums[i];
            if (indexMap.find(partner) != indexMap.end()) {
                return vector<int>{indexMap[partner], i};
            }
            indexMap[nums[i]] = i;
        }
        return {};
    }
};
// @lc code=end

