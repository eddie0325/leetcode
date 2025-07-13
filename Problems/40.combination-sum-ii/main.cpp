/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> current;
        // 排序，方便跳過重複元素會有重複組合問題
        // 1,1,2,3
        // o x o o
        // x o o o 會算到兩次
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, ans, current, 0);
        return ans;
    }

    void backtrack(const vector<int>& nums, int target, vector<vector<int>>& ans, vector<int>& current, int startIndex) {
        // 已達到目標
        if (target == 0) {
            ans.push_back(current);
            return;
        }
        // 超出目標
        else if (target < 0 || startIndex >= nums.size())
            return;

        for (int i = startIndex; i < nums.size(); i++) {
            // 上一層跳過了，又遇到一樣的數字也跳過
            if (i > startIndex && nums[i] == nums[i - 1])
                continue;
            current.push_back(nums[i]);
            backtrack(nums, target - nums[i], ans, current, i + 1); // i + 1表示同個元素只能用一次
            current.pop_back();
        }
    }
};
// @lc code=end

