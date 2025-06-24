/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int maxLength = 0;
        unordered_map<char, int> used;
        for (int i = 0; i < s.length(); i++) {
            char character = s[i];
            if (used.find(character) != used.end() && used[character] >= left) {
                left = used[character] + 1;
            }
            used[character] = i;
            maxLength = max(maxLength, i - left + 1);
        }
        return maxLength;
    }
};
// @lc code=end

