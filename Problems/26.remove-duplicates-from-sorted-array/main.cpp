/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */

// @lc code=start
// #define DEBUG
#include <vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // 參考 leetcode 80，是此題的進階版本
        int updateIndex = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (updateIndex == 0 || nums[i] != nums[updateIndex - 1]) {
                nums[updateIndex++] = nums[i];
            }
        }
        return updateIndex;
    }
};
#ifdef DEBUG
int main() {
    Solution s;
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    int ans = s.removeDuplicates(nums);
    return 0;
}
#endif
// @lc code=end

