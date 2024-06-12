/*
 * @lc app=leetcode id=974 lang=cpp
 *
 * [974] Subarray Sums Divisible by K
 */

// @lc code=start
// #KEYPOINT prefix sum
// #define DEBUG
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        // prefix sum
        // subarray i to j = sum[j] - sum[i - 1]
        unordered_map<int, int> remainder;
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0) {
                nums[i] += nums[i - 1];
            }
            // 確保是正數
            nums[i] = (nums[i] + k * 10000) % k;
            remainder[nums[i]]++;
        }
        // 相減能被k整除 表示兩個%k的值相同
        int ans = 0;
        for (auto it = remainder.begin(); it != remainder.end(); it++) {
            // 如果是0，自己也能成subarray
            if (it->first == 0) {
                ans += it->second;
            }

            int count = it->second;
            // Cn取2
            ans += count * (count - 1) / 2;
        }
        return ans;
    }
};
#ifdef DEBUG
int main() {
    Solution s;
    int k = 9;
    vector<int> nums = {5};
    int ans = s.subarraysDivByK(nums, k);
    return 0;
}
#endif
// @lc code=end

