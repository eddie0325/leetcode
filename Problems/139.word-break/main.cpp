/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 */

// @lc code=start
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int l = s.length();
        // dp[i] 表示 s[0 ~ i-1]是可以被組出來的
        vector<bool> dp(l + 1, false);
        dp[0] = true;

        // 計算字典中最長單字長度
        int maxLen = 0;

        for (auto &w : wordDict) maxLen = max(maxLen, (int)w.size());
        // 建立原字串的 string_view，避免 substr 複製
        string_view sv(s);
        unordered_set<string_view> wordSet(wordDict.begin(), wordDict.end());
        
        for (int i = 1; i <= l; i++) {
            // j 從 i - maxLen 開始，避免檢查比字典單字長度還長的子字串
            for (int j = max(0, i - maxLen); j < i; j++) {
                if (dp[j] && wordSet.find(sv.substr(j, i - j)) != wordSet.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[l];
    }
};
// @lc code=end

