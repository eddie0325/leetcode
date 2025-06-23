/*
 * @lc app=leetcode id=167 lang=cpp
 *
 * [167] Two Sum II - Input Array Is Sorted
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0;
        int j = numbers.size() - 1;
        while(i < j) {
            int sum = numbers[i] + numbers[j];
            if (sum < target) {
                i++;
            }
            else if (sum > target) {
                j--;
            }
            else {
                return {i + 1, j + 1};
            }
        }
        return {};
    }
};
// @lc code=end

