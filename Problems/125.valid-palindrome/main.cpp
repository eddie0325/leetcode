/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.length() - 1;
        while(i < j) {
            while(i < j && !isAlphanumericalCharacters(s[i])) i++;
            while(i < j && !isAlphanumericalCharacters(s[j])) j--;
            
            if (!isSame(s[i], s[j]))
                return false;
            i++;
            j--;
        }
        return true;
    }
    bool isAlphanumericalCharacters(char c){
        return 
            (c >= 'a' && c <= 'z') || 
            (c >= 'A' && c <= 'Z') ||
            (c >= '0' && c <= '9');
    }
    bool isSame(char a, char b) {
        if (a >= 'A' && a <= 'Z')
            a = a - 'A' + 'a';
        if (b >= 'A' && b <= 'Z')
            b = b - 'A' + 'a';
        return a == b;
    }
};
// @lc code=end

