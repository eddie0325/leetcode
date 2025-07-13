/*
 * @lc app=leetcode id=621 lang=cpp
 *
 * [621] Task Scheduler
 */

// @lc code=start
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> taskCounts(26);
        int maxCount = 0;

        // 先統計任務數量並找出最大值
        for (char task: tasks) {
            taskCounts[task - 'A']++;
            maxCount = max(maxCount, taskCounts[task - 'A']);
        }
        // 有多少個任務達到最大值
        int num_of_maxCount = 0;
        for (int count: taskCounts) {
            if (count == maxCount)
                num_of_maxCount++;
        }

        // 計算理論上的最短時間：
        // (maxCount - 1) 個 full cycle，每個 cycle 有 (n + 1) 格子，最後加上最後一組最大頻率的任務
        int ans = (maxCount - 1) * (n + 1);
        ans += num_of_maxCount;
        // 如果任務總數更多，說明可以塞滿所有 idle，實際需要的時間就是任務數量
        ans = max(ans, static_cast<int>(tasks.size()));
        return ans;
    }
};
// @lc code=end

