/*
 * @lc app=leetcode id=88 lang=cpp
 *
 * [88] Merge Sorted Array
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (n == 0) return;
        vector<int> result(m + n);
        // 兩個pointer來找小到大
        int next_i = 0;
        int next_j = 0;
        for (int i = 0; i < m + n; ++i) {
            if (next_i == m) {
                result[i] = nums2[next_j++];
                continue;
            }
            if (next_j == n) {
                result[i] = nums1[next_i++];
                continue;
            }
            result[i] = nums1[next_i] < nums2[next_j] ? nums1[next_i++] : nums2[next_j++];
        }
        for (int i = 0; i < m + n; ++i) {
            nums1[i] = result[i];
        }
        // 如果從後面開始排大到小，就不用另外開result來存
    }
};
// @lc code=end

