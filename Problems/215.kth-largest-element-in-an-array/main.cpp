/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 */

// @lc code=start
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        auto cmp = [](int a, int b) {
            return a > b;
        };
        priority_queue<int, vector<int>, decltype(cmp)> minHeap(cmp);
        for(int num: nums) {
            minHeap.push(num);
            if (minHeap.size() > k)
                minHeap.pop();
        }
        return minHeap.top();
    }
};
// @lc code=end

