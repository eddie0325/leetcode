/*
 * @lc app=leetcode id=309 lang=cpp
 *
 * [309] Best Time to Buy and Sell Stock with Cooldown
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // dp[i][狀態] 表示第i天結束最大利益
        // dp[i][0] 今天休息
        // dp[i][1] 今天持股
        // dp[i][2] 今天剛賣
        vector<vector<int>> dp(n, vector<int>(3, 0));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        dp[0][2] = -INT_MAX;
        for (int i = 1; i < n; i++) {
            // 今天休息：昨天休息或昨天剛賣
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][2]);
            // 今天持股：昨天持股或今天剛買
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
            // 今天剛賣：昨天持股
            dp[i][2] = dp[i - 1][1] + prices[i];
        }
        return max(dp[n - 1][0], dp[n -1][2]);
    }
};
// @lc code=end

