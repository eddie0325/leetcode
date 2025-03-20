/*
 * @lc app=leetcode id=2401 lang=cpp
 *
 * [2401] Longest Nice Subarray
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        // 符合條件的sub array中，每個bit都只能有一個元素使用
        
        int usedbits = 0;

        // sub array，用slide window來找
        int left = 0;
        int right = 0;
        int maxLength = 0;

        for (right = 0; right < nums.size(); ++right) {
            // 新的數字是否與sub array既有bit衝突
            while ((usedbits & nums[right]) != 0) {
                // 把最左用的bit拿掉
                usedbits ^= nums[left];
                left++;
            }
            usedbits |= nums[right];
            maxLength = max(maxLength, right - left + 1);
        }
        return maxLength;
    }
};

// #define DEBUG
#ifdef DEBUG
int main() {
    Solution solution;
    vector<int> nums = {3,1,5,11,13};
    auto r = solution.longestNiceSubarray(nums);
    cout << "r: " << r << endl;
    return 0;
}
#endif
// @lc code=end

