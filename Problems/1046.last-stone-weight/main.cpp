/*
 * @lc app=leetcode id=1046 lang=cpp
 *
 * [1046] Last Stone Weight
 */

// @lc code=start
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap;
        for (int stone: stones)
            maxHeap.push(stone);

        while(maxHeap.size() > 1) {
            int a = maxHeap.top();
            maxHeap.pop();
            int b = maxHeap.top();
            maxHeap.pop();
            if (a != b)
                maxHeap.push(a - b);
        }
        return maxHeap.empty() ? 0 : maxHeap.top();
    }
};
// @lc code=end

