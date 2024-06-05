/*
 * @lc app=leetcode id=80 lang=cpp
 *
 * [80] Remove Duplicates from Sorted Array II
 */

// @lc code=start
// #define DEBUG
#include <vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int updateIndex = 0;
        for (int i = 0; i < nums.size(); i++) {
            // 前兩個一定是nums[0][1]
            // 接下來按照nums來填值，只要確保同個值不要填到第三次就行
            if (updateIndex <= 1 || nums[i] != nums[updateIndex - 2]) {
                nums[updateIndex++] = nums[i];
            }
        }
        return updateIndex;
    }
};
#ifdef DEBUG
int main() {
    Solution s;
    vector<int> nums = {1,1,1,2,2,3};
    int ans = s.removeDuplicates(nums);
    return 0;
}
#endif
// @lc code=end

