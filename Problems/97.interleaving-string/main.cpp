/*
 * @lc app=leetcode id=97 lang=cpp
 *
 * [97] Interleaving String
 */

// @lc code=start
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int l1 = s1.length();
        int l2 = s2.length();
        if (l1 + l2 != s3.length())
            return false;
        vector<vector<bool>> dp(l1 + 1, vector<bool>(l2 + 1, false));
        // dp[i][j]表示s1取i個 s2取j個 能否組出s3(i+j)
        dp[0][0] = true;
        for (int i = 0; i <= l1; i++)
            for (int j = 0; j <= l2; j++) {
                // 從s1取字
                if (i > 0 && dp[i - 1][j] && s1[i - 1] == s3[i + j - 1])
                    dp[i][j] = true;
                // 從s2取字
                if (j > 0 && dp[i][j - 1] && s2[j - 1] == s3[i + j - 1])
                    dp[i][j] = true;
            }
        return dp[l1][l2];
    }
};
// @lc code=end

