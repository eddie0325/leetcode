/*
 * @lc app=leetcode id=330 lang=cpp
 *
 * [330] Patching Array
 */

// @lc code=start
#define DEBUG
#include <vector>
using namespace std;
class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int patches = 0;
        // 目前能湊到的值(1~availValue都湊得到)
        long long availValue = 0;
        int i = 0;
        while(availValue < n) {
            // nums還有值，且他的值能幫助availValue的範圍變大
            // 1, 2 ...availValue都能湊到
            // 那再加nums[i]
            // 就會變成1, 2,...availValue + nums[i]都能湊到
            if (i < nums.size() && availValue + 1 >= nums[i]) {
                int patchNum = nums[i];
                // 能湊的值域多了nums[i]
                availValue += nums[i];
                i++;
            }
            else {
                // patch一個availValue + 1
                // 讓值域變成2availValue + 1
                // 1,2,...x都能湊到
                // 那再加入一個數x+1
                // 就1,2 ... 2x+1都能湊到
                int patchNum = availValue + 1;
                patches++;
                availValue += patchNum;
            }
            
        }
        return patches;
    }
};
#ifdef DEBUG
int main() {
    Solution s;
    vector<int> nums = {1,2,31,33};
    int n = 2147483647;
    int patches = s.minPatches(nums, n);
    return 0;
}
#endif
// @lc code=end

