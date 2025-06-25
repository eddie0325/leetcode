/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 */

// @lc code=start
// #KEYPOINT Sliding Window
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> targetMap; // 目標
        unordered_map<char, int> windowMap; // 目前window
        string finalAns = "";
        int ansLeftIndex = -1;
        int ansLength = INT_MAX;
        
        for (int i = 0; i < t.length(); i++)
            targetMap[t[i]]++;
        
        int left = 0;
        int right = 0;
        int targetMatch = targetMap.size(); // 不包含重複字元 AABC算3
        int nowMatch = 0; // 達成的字元種數

        while(right < s.length()) {
            char c = s[right];
            windowMap[c]++;

            if (targetMap.find(c) != targetMap.end() && windowMap[c] == targetMap[c]) {
                nowMatch++;
            }
            while (nowMatch == targetMatch) {
                int leng = right - left + 1;
                if (leng < ansLength) {
                    ansLength = leng;
                    ansLeftIndex = left;
                }
                char removeChar = s[left];
                windowMap[removeChar]--;
                if (targetMap.find(removeChar) != targetMap.end() && windowMap[removeChar] < targetMap[removeChar]) {
                    nowMatch--;
                }
                left++;
            }
            right++;
        }

        // 最後再取substr，不然會TLE
        if (ansLength != INT_MAX)
            finalAns = s.substr(ansLeftIndex, ansLength);
        return finalAns;
    }
};
// @lc code=end

