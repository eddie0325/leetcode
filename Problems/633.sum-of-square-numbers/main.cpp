/*
 * @lc app=leetcode id=633 lang=cpp
 *
 * [633] Sum of Square Numbers
 */

// @lc code=start
#include <cmath>
using namespace std;
class Solution {
public:
    bool isInteger(double x) {
        return trunc(x) == x;
    }
    bool judgeSquareSum(int c) {
        // sqrt(2^31-1) = 46340.9XX
        for (int i = 0; i < 46341 && i * i <= c; ++i) {
            double another = sqrt(c - i * i);
            if (isInteger(another)) {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end

