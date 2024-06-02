/*
 * @lc app=leetcode id=3171 lang=cpp
 *
 * [3171] Find Subarray With Bitwise AND Closest to K
 */

// @lc code=start
#define DEBUG
#include <vector>
#include <set>
using namespace std;
class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        // dp[i]表示以nums[i]當結尾，所有subarray的AND可能的值
        // 用set是因為不需要重複的數字
        vector<set<int>> dp(nums.size());
        int minValue = INT_MAX;

        for (int i = 0; i < nums.size(); ++i) {
            // 更新這輪dp的內容
            // 包含上一輪dp&這輪數字 dp[i-1]&nums[i]
            // 還有這輪數字本身 
            set<int> s;
            if (i > 0) {
                for (int t : dp[i - 1]) {
                    s.insert(t & nums[i]);
                }
            }
            s.insert(nums[i]);

            // 更新最小差值
            for (int t : s) {
                minValue = min(minValue, abs(k - t));
            }
            // 設定dp
            dp[i] = s;
        }
        return minValue;
    }
};
#ifdef DEBUG
int main() {
    Solution s;
    vector<int> nums = {1, 2, 4, 5,};
    int k = 3;
    int a = s.minimumDifference(nums, k);
    return 0;
}
#endif
// @lc code=end

