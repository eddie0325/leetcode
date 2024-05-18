/*
 * @lc app=leetcode id=3146 lang=cpp
 *
 * [3146] Permutation Difference between Two Strings
 */

// @lc code=start
#include <string>
using namespace std;
class Solution {
public:
    int findPermutationDifference(string s, string t) {
        // index in s
        int index_of_s[26];
        for(int i = 0;i < s.size();i++) {
            index_of_s[s[i] - 'a'] = i;
        }
        int sum = 0;
        for(int i = 0;i < t.size();i++) {
            sum += abs(index_of_s[t[i] - 'a'] - i);
        }
        return sum;
    }
};
// @lc code=end

