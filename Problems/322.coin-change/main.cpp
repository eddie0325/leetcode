/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 */

// @lc code=start
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // dp[i] = 湊到金額 i 的最少硬幣數
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        sort(coins.begin(), coins.end());
        for (int i = 1; i <= amount; i++) {
            for(auto coin: coins) {
                if (coin > i) break;
                // 只要 i-coin 可達，就能用 coin 到達
                if (coin <= i && dp[i - coin] != INT_MAX) {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }

            }
        }
        return dp[amount] != INT_MAX ? dp[amount] : -1;
    }
};
// @lc code=end

