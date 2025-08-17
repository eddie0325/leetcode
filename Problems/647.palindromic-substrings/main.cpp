/*
 * @lc app=leetcode id=647 lang=cpp
 *
 * [647] Palindromic Substrings
 */

// @lc code=start
class Solution {
public:
    int countSubstrings(string s) {
        int l = s.length();
        vector<vector<bool>> dp(l, vector<bool>(l, false));
        for (int i = 0; i < l; i++)
            dp[i][i] = true;
        int count = l;
        for (int len = 2; len <= l; len++) {
            for (int i = 0; i <= l - len; i++) {
                int j = i + len - 1;
                // 長度 2 或 3 只要頭尾相等就回文
                // 長度 > 3 需內層子串也是回文
                if (s[i] == s[j] && (len <= 3 || dp[i + 1][j - 1])) {
                    dp[i][j] = true;
                    count++;
                }
            }
        }
        return count;
    }
};
// @lc code=end

