/*
 * @lc app=leetcode id=1608 lang=cpp
 *
 * [1608] Special Array With X Elements Greater Than or Equal X
 */

// @lc code=start
// #define DEBUG
#include <vector>
using namespace std;
class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        // 排序後，arr[index - 1] >= index 表示至少有index個數 >= index，再檢查下一個是否也 >= index
        // i == n 時，已沒有下一個，跳過檢查 
        int n = nums.size();
        int ans = -1;
        for (int i = 1; i <= n; ++i) {
            if (nums[i - 1] >= i && ((i == n) || nums[i] < i)) {
                if (ans != -1) { // 要unique
                    return -1;
                }
                ans = i;
            }
        }
        return ans;
    }
};

#ifdef DEBUG
int main() {
    Solution s;
    vector<int> nums = {0,0};
    int ans = s.specialArray(nums);
    return 0;
}
#endif
// @lc code=end

