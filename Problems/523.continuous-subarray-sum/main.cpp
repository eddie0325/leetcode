/*
 * @lc app=leetcode id=523 lang=cpp
 *
 * [523] Continuous Subarray Sum
 */

// @lc code=start
// #KEYPOINT prefix sum
#define DEBUG
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        // subarray sum i to j = sum[j] - sum[i-1]
        // 因此在sum中找到餘數相同的sum[i],sum[j]，就表示找到subarray i+1 to j
        unordered_map<int, int> remainder; // <餘數, index>
        int sum = 0;
        remainder[0] = -1;

        for (int i = 0; i < nums.size(); ++i) {
            sum = (sum + nums[i]) % k;
            if (remainder.find(sum) != remainder.end()) {
                // 長度至少為2
                if (i - remainder[sum] > 1) {
                    return true;
                }
            }
            else {
                // 只存最早看到的
                remainder[sum] = i;
            }
        }
        return false;
    }
};
#ifdef DEBUG
int main() {
    Solution s;
    vector<int> nums = {5,0,0,0};
    int k = 3;
    bool ans = s.checkSubarraySum(nums, k);
    return 0;
}
#endif
// @lc code=end

