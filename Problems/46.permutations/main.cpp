/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> current;
        vector<bool> used(nums.size(), false); // 紀錄已被使用過
        backtrack(nums, ans, current, used);
        return ans;
    }

    void backtrack(const vector<int>& nums, vector<vector<int>> &ans, vector<int>& current, vector<bool> &used) {
        if (current.size() == nums.size()) {
            ans.push_back(current);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (!used[i]) {
                current.push_back(nums[i]);
                used[i] = true;
                backtrack(nums, ans, current, used);
                current.pop_back();
                used[i] = false;
            }
        }
    }
};
// @lc code=end

