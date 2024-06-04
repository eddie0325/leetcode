/*
 * @lc app=leetcode id=409 lang=cpp
 *
 * [409] Longest Palindrome
 */

// @lc code=start
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> m;
        int pairCount = 0;
        
        for (int i = 0; i < s.size(); i++) {
            if (m.find(s[i]) == m.end()) {
                m[s[i]] = 1;
            } else {
                m[s[i]]++;
                // 變偶數了，組出一個pair
                pairCount += m[s[i]] % 2 == 0 ? 1 : 0;
            }
        }
        
        int ans = pairCount * 2;
        // 塞一個任意奇數當中間
        if (ans != s.size()) 
            ans++;
        return ans;
    }
};
// @lc code=end

