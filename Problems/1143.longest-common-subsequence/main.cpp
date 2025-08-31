/*
 * @lc app=leetcode id=1143 lang=cpp
 *
 * [1143] Longest Common Subsequence
 */

// @lc code=start
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();
        // memo[i][j] = LCS 長度 of text1[0..i-1], text2[0..j-1]
        vector<vector<int>> memo(m + 1, vector<int>(n + 1, -1));
        return lcs(text1, text2, m, n, memo);
    }

    int lcs(string& text1, string& text2, int i, int j, vector<vector<int>>& memo) {
        if (i == 0 || j == 0)
            return 0;
        if (memo[i][j] != -1) return memo[i][j];
        
        // 如果最尾相等，dp[i][j] = 1 + dp[i-1][j-1]
        if (text1[i - 1] == text2[j - 1])
            memo[i][j] = 1 + lcs(text1, text2, i - 1, j - 1, memo);
        // 最尾端不相等，dp[i][j] = max(dp[i-1][j], dp[i][j-1])
        else
            memo[i][j] = max(lcs(text1, text2, i - 1, j, memo), lcs(text1, text2, i, j - 1, memo));
        return memo[i][j];
    }
};
// @lc code=end

