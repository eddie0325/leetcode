/*
 * @lc app=leetcode id=3153 lang=cpp
 *
 * [3153] Sum of Digit Differences of All Pairs
 */

// @lc code=start
// #define DEBUG
#include <vector>
using namespace std;
class Solution {
public:
    long long digitCount[10];
    long long sumSingleDigitDifferences() {
        long long sum = 0;
        for (int i = 0; i < 10; ++i) {
            if (digitCount[i] > 0) {
                for (int j = i + 1; j < 10; ++j) {
                    if (digitCount[j] > 0) {
                        // 題目是要計算difference幾次，如果要計算difference差值就是
                        // sum += (j - i) * (digitCount[i]) * (digitCount[j]);
                        sum += (1) * (digitCount[i]) * (digitCount[j]);
                    }
                }
            }
        }
        return sum;
    }

    long long sumDigitDifferences(vector<int>& nums) {
        long long sum = 0;
        // num < 10e9 所以數字最大9位數
        // 每次計算一個位數的結果
        for (int i = 1; i <= 9; ++i) {
            memset(digitCount, 0, sizeof(digitCount));
            for (int j = 0; j < nums.size(); ++j) {
                digitCount[nums[j] % 10]++;
                nums[j] /= 10;
            }
            sum += sumSingleDigitDifferences();
        }
        return sum;
    }
};
#ifdef DEBUG
int main() {
    Solution s;
    vector<int> nums = {13,23,12};
    auto ans = s.sumDigitDifferences(nums);
    return 0;
}
#endif
// @lc code=end

