/*
 * @lc app=leetcode id=213 lang=cpp
 *
 * [213] House Robber II
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size(), ans;
        if (n == 1) return nums[0];
        vector<int> dp(n, 0);
        // 偷第0間，最後一間不能偷 (0 ~ n-2)
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < n - 1; i++)
            dp[i] = max((dp[i - 2] + nums[i]), dp[i - 1]);
        // 取n - 2的答案，因最後一間不能偷
        ans = dp[n - 2];

        // 不偷第0間，最後一間可以偷 (1 ~ n-1)
        dp[0] = 0;
        dp[1] = nums[1];
        for (int i = 2; i < n; i++)
            dp[i] = max((dp[i - 2] + nums[i]), dp[i - 1]);
        // 比較兩個結果誰比較大
        ans = max(ans, dp[n - 1]);
        return ans;
    }
};
// @lc code=end

