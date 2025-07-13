/*
 * @lc app=leetcode id=703 lang=cpp
 *
 * [703] Kth Largest Element in a Stream
 */

// @lc code=start
class KthLargest {
public:
    struct compare {
        bool operator()(int a, int b) {
            return a > b;
        }
    };

    priority_queue<int, vector<int>, greater<int>> minHeap;
    // priority_queue<int, vector<int>, compare> minHeap;
    int kth = 0;

    KthLargest(int k, vector<int>& nums) {
        kth = k;
        for (int num: nums) {
            minHeap.push(num);
            if (minHeap.size() > k) minHeap.pop();
        }
    }

    int add(int val) {
        minHeap.push(val);
        if (minHeap.size() > kth) minHeap.pop();
        return minHeap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
// @lc code=end

