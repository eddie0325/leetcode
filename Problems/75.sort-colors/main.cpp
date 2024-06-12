/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 */

// @lc code=start
#define DEBUG
#include <vector>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zeroPointer = 0;
        int twoPointer = nums.size() - 1;
        int checkPointer = 0;
        int tmp;
        while(checkPointer <= twoPointer) {
            if (nums[checkPointer] == 0) {
                // checkPointer過的只可能是0或1
                // 不可能是2，所以checkPointer可以++往後檢查
                nums[checkPointer++] = nums[zeroPointer];
                nums[zeroPointer++] = 0;
            }
            else if (nums[checkPointer] == 2) {
                // 後面換回來的要再檢查
                nums[checkPointer] = nums[twoPointer];
                nums[twoPointer--] = 2;
            }
            else {
                checkPointer++;  
            }
        }
    }
};

#ifdef DEBUG
int main() {
    vector<int> nums = {2,0,2,1,1,0};
    Solution s;
    s.sortColors(nums);
    return 0;
}
#endif
// @lc code=end

