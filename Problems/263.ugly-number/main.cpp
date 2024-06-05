/*
 * @lc app=leetcode id=263 lang=cpp
 *
 * [263] Ugly Number
 */

// @lc code=start
class Solution {
public:
    bool isUgly(int n) {
        // ugly number是正數
        if (n < 1) {
            return false;
        }
        if (n == 1) {
            return true;
        }
        while(n != 2 && n != 3 && n != 5) {
            if (n % 2 == 0) {
                n /= 2;
            } else if (n % 3 == 0) {
                n /= 3;
            } else if (n % 5 == 0) {
                n /= 5;
            } else {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

