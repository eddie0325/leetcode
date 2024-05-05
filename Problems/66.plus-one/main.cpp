/*
 * @lc app=leetcode id=66 lang=cpp
 *
 * [66] Plus One
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for (int i = digits.size() - 1; i >= 0; i--) {
            digits[i] += 1;
            if (digits[i] > 9) {
                digits[i] = 0;
                if (i == 0) { // 首位時進位要多一位數
                    digits.insert(digits.begin(), 1);
                }
            }
            else {
                break;
            }
        }
        return digits;
    }
};
// @lc code=end

