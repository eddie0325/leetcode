/*
 * @lc app=leetcode id=424 lang=cpp
 *
 * [424] Longest Repeating Character Replacement
 */

// @lc code=start
// #KEYPOINT Sliding Window
class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0;
        int maxLength = 0;
        int maxCount = 0;
        unordered_map<char, int> countMap;

        for (int i = 0; i < s.length(); i++) {
            countMap[s[i]]++;
            maxCount = max(countMap[s[i]], maxCount);
            
            // 判斷這次增加是否合法，不合法要縮視窗
            // 目前長度應<=最大數量+k
            if (i - left + 1 > maxCount + k) {
                countMap[s[left]]--;
                left++;
            }
            else {
                maxLength = max(maxLength, i - left + 1);
            }
        }
        return maxLength;
    }
};
// @lc code=end

