/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> current;
        backtrack(nums, ans, current, 0);
        return ans;
    }

    void backtrack(const vector<int>& nums, vector<vector<int>>& ans, vector<int>& current, int currentIndex) {
        // if (currentIndex >= nums.size()) {
        //     ans.push_back(current);
        //     return;
        // }
        // current.push_back(nums[currentIndex]);
        // backtrack(nums, ans, current, currentIndex + 1);
        // current.pop_back();
        // // 不選的話，之後也不能選相同數字了，不然會出現重複組合
        // // 1 1 2 3
        // // O X O O
        // // X O O O
        // int newIndex = currentIndex + 1;
        // while(newIndex < nums.size() && nums[newIndex] == nums[currentIndex]) {
        //     newIndex++;
        // }
        // backtrack(nums, ans, current, newIndex);

        ans.push_back(current);

        for (int i = currentIndex; i < nums.size(); i++) {
            // 跳過重複：只有當 i 是該層第一個 或 不等於前一個數，才納入
            if (i > currentIndex && nums[i] == nums[i - 1])
                continue;
            current.push_back(nums[i]);
            backtrack(nums, ans, current, i + 1);
            current.pop_back();
        }
    }
};
// @lc code=end

