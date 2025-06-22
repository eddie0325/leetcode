/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 */

// @lc code=start
class Solution {
public:
    bool isAnagram(string s, string t) {
        int charCount[26] = {0};
        if (s.length() != t.length())
            return false;
        for (char c: s) {
            charCount[c - 'a']++;
        }
        for (char c: t) {
            charCount[c - 'a']--;
            if (charCount[c - 'a'] < 0)
                return false;
        }
        return true;
    }
};
// @lc code=end

