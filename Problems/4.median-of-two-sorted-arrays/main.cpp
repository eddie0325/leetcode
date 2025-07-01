/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */

// @lc code=start
// #KEYPOINT Binary Search
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // 找合併後第k小的元素
        // nums1取i個，nums2找k-i個
        // 左邊元素由 nums1[0~i-1] nums2[0~k-i-1]組成
        // 左邊元素的最大<=右邊元素的最小
        // nums1[i-1] <= nums2[k-i]
        // nums2[k-i-1] <= nums1[i]

        int m = nums1.size();
        int n = nums2.size();
        int total = m + n;
        int k = (total + 1) / 2;
        // 對比較短的做binary search
        vector<int>& sArray = (m < n) ? nums1 : nums2;
        vector<int>& lArray = (m < n) ? nums2 : nums1;
        
        int left = 0;
        int right = sArray.size(); // sArray全部使用的情況
        while(left <= right) {
            int i = left + (right - left) / 2;
            int j = k - i;
            int left_max_sArray = (i == 0) ? INT_MIN : sArray[i - 1];
            int left_max_lArray = (j == 0) ? INT_MIN : lArray[j - 1];
            int right_min_sArray = (i == sArray.size()) ? INT_MAX : sArray[i];
            int right_min_lArray = (j == lArray.size())? INT_MAX : lArray[j];

            // 找到了
            if (left_max_sArray <= right_min_lArray && left_max_lArray <= right_min_sArray) {
                if (total % 2 == 1) 
                    return max(left_max_sArray, left_max_lArray);
                else {
                    int first = max(left_max_sArray, left_max_lArray);
                    int second = min(right_min_sArray, right_min_lArray);
                    return (double)(first + second) / 2.0;
                }
            }
            if (left_max_sArray > right_min_lArray) { // i 太大
                right = i - 1;
            }
            else if (left_max_lArray > right_min_sArray) { // i 太小
                left = i + 1;
            }
        }
        return -1;
    }
};
// @lc code=end

