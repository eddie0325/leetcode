/*
 * @lc app=leetcode id=518 lang=cpp
 *
 * [518] Coin Change II
 */

// @lc code=start
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<unsigned long long> dp(amount + 1, 0);
        dp[0] = 1;
        for (int coin: coins) {
            for (int i = coin; i <= amount; i++) {
                // 對於每個金額，加入使用這個 coin 的組合數
                dp[i] += dp[i - coin];
            }
        }
        return dp[amount];
    }
};
// @lc code=end

