/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> combination;
        int currentSum = 0;
        backtrack(nums, target, ans, combination, 0, currentSum);
        return ans;
    }

    void backtrack(const vector<int>& nums, const int& target, vector<vector<int>>& ans, vector<int>& current, int startIndex, int& currentSum) {
        if (currentSum > target)
            return;
        else if (currentSum == target) {
            ans.push_back(current);
            return;
        }
        for (int i = startIndex; i < nums.size(); i++) {
            current.push_back(nums[i]);
            currentSum += nums[i];
            // 可以重複使用相同元素，因此下一層遞迴仍從 i 開始
            backtrack(nums, target, ans, current, i, currentSum);
            current.pop_back();
            currentSum -= nums[i];
        }
    }
};
// @lc code=end

