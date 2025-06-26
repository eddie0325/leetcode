/*
 * @lc app=leetcode id=239 lang=cpp
 *
 * [239] Sliding Window Maximum
 */

// @lc code=start
// #KEYPOINT deque
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // priority_queue + unordered_map 搭配延遲刪除法（lazy deletion)
        // O(n log k)
        // vector<int> ans;
        // unordered_map<int, int> windowMap;
        // priority_queue<int> maxHeap;
        // int left = 0;
        // for (int i = 0; i < nums.size(); i++) {
        //     windowMap[nums[i]]++;
        //     maxHeap.push(nums[i]);
            
        //     if (i - left + 1 > k) {
        //         windowMap[nums[left]]--;
        //         left++;
        //     }

        //     if (i - left + 1 == k) {
        //         while(maxHeap.size() > 0) {
        //             int value = maxHeap.top();
        //             if (windowMap[value] > 0) {
        //                 ans.push_back(value);
        //                 break;
        //             }
        //             maxHeap.pop();
        //         }
        //     }
        // }
        // return ans;


        // 單調遞減 deque
        // O(n)
        vector<int> ans;
        deque<int> dq; // front 存最大值 從end加

        for (int i = 0; i < nums.size(); i++) {
            // 已經超出視窗了
            if (dq.size() > 0 && dq.front() <= i - k) 
                dq.pop_front();

            // 新值加入dq，把小於新值的都踢掉
            while(dq.size() > 0 && nums[dq.back()] < nums[i])
                dq.pop_back();
            dq.push_back(i);

            // 視窗長度到達k後，產生答案
            if (i + 1 >= k)
                ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};
// @lc code=end

