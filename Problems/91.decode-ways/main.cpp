/*
 * @lc app=leetcode id=91 lang=cpp
 *
 * [91] Decode Ways
 */

// @lc code=start
class Solution {
public:
    int numDecodings(string s) {
        int l = s.length();
        if (l == 0 || s[0] == '0') return 0;

        vector<int> dp(l, 0);
        dp[0] = 1;

        for (int i = 1; i < l; i++) {
            // 單字元有效
            if (s[i] != '0') {
                dp[i] += dp[i - 1];
            }
            // 兩字元有效
            int num = 10 * (s[i - 1] - '0') + (s[i] - '0');
            if (num >= 10 && num <= 26) {
                dp[i] += (i == 1 ? 1 : dp[i - 2]);
            }
        }
        return dp[l - 1];
    }
};
// @lc code=end

