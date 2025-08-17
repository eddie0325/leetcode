/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        int l = s.length();
        int maxLength = 1;
        int startIndex = 0;
        // dp[i][j] = true 表示 s[i..j] 是回文
        vector<vector<bool>> dp(l, vector<bool>(l, false));
        for (int i = 0; i < l; i++)
            dp[i][i] = true;
        // 字串長度 從2開始慢慢增加
        for (int len = 2; len <= l; len++) {
            for (int i = 0; i <= l - len; i++) {
                int j = i + len - 1;
                // 長度 2 或 3 只要頭尾相等就回文
                // 長度 > 3 需內層子串也為回文
                if(s[i] == s[j] && (j - i < 3 || dp[i + 1][j - 1])) {
                    dp[i][j] = true;
                    if (len > maxLength) {
                        startIndex = i;
                        maxLength = len;
                    }
                }
            }
        }
        return s.substr(startIndex, maxLength);
    }
};
// @lc code=end

