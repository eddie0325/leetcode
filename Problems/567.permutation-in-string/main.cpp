/*
 * @lc app=leetcode id=567 lang=cpp
 *
 * [567] Permutation in String
 */

// @lc code=start
// #KEYPOINT Sliding Window
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> targetCount(26, 0);
        vector<int> windowCount(26, 0);

        if (s1.length() > s2.length()) 
            return false;
            
        int nowCount = s1.length();
        for(int i = 0; i < s1.length(); i++) {
            targetCount[s1[i] - 'a']++;
        }

        int left = 0;
        for (int i = 0; i < s2.length(); i++) {
            int letter = s2[i] - 'a';
            windowCount[letter]++;
            if (i - left + 1 > s1.length()) {
                windowCount[s2[left] - 'a']--;
                left++;
            }
            if (targetCount == windowCount)
                return true;
        }
        return false;
    }
};
// @lc code=end

