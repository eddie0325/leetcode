/*
 * @lc app=leetcode id=3168 lang=cpp
 *
 * [3168] Minimum Number of Chairs in a Waiting Room
 */

// @lc code=start
#include <string>
using namespace std;
class Solution {
public:
    int minimumChairs(string s) {
        int maxCount = 0;
        int now = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == 'E') {
                now++;
            }
            else{
                now--;
            }
            maxCount = max(maxCount, now);
        }
        return maxCount;
    }
};
// @lc code=end

