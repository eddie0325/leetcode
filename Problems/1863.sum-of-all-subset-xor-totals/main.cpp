/*
 * @lc app=leetcode id=1863 lang=cpp
 *
 * [1863] Sum of All Subset XOR Totals
 */

// @lc code=start
// #define DEBUG
#include <vector>
using namespace std;
class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        // 第一個位元 有X個是1 Y個是0 X+Y=N
        // All subsets 有2^N個
        /*
        只要有X，有一半的挑法會讓XOR=1
        example:
        X = 3 Y = 0
        1 1 1 1 0 0 0 0
        1 1 0 0 1 1 0 0
        1 0 1 0 1 0 1 0 

        1 0 0 1 0 1 1 0 = 4


        X = 2 Y = 1
        1 1 1 1 0 0 0 0
        1 1 0 0 1 1 0 0
        1 0 1 0 1 0 1 0 Y

        0 0 1 1 1 1 0 0 = 4


        X = 1 Y =2
        1 1 1 1 0 0 0 0 X
        1 1 0 0 1 1 0 0
        1 0 1 0 1 0 1 0 

        1 1 1 1 0 0 0 0 = 4


        X = 0 Y = 3
        0
        */

        int n = nums.size();
        int setCount = pow(2, n);

        // 檢查該bit有沒有過有值
        int bitMask = 0;
        for (int i = 0; i < n; i++) {
            bitMask |= nums[i];
        }
        // 一半的挑法會讓XOR=1
        int sum = bitMask * (setCount / 2);
        return sum;
    }
};

#ifdef DEBUG
int main() {
    Solution s;
    vector<int> nums = {3,4,5,6,7,8};
    int r = s.subsetXORSum(nums);
    return 0;
}
#endif
// @lc code=end

