/*
 * @lc app=leetcode id=826 lang=cpp
 *
 * [826] Most Profit Assigning Work
 */

// @lc code=start
#define DEBUG
#include <vector>
using namespace std;
class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int, int>> jobs(difficulty.size());
        for (int i = 0; i < difficulty.size(); i++) {
            jobs[i] = make_pair(profit[i], difficulty[i]);
        }
        sort(jobs.begin(), jobs.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            if (a.first == b.first) {
                return a.second <b.second;
            }
            return a.first > b.first;
        });
        // 其實也不用過濾，邏輯上本來就不會被挑到
        // // 過濾到CP值不高的工作 dif高profit低
        // int lastDiff = INT_MAX;
        // int index = 0;
        // while (index < jobs.size()) {
        //     if (lastDiff < jobs[index].second) {
        //         jobs.erase(jobs.begin() + index);
        //         continue;
        //     }
        //     lastDiff = jobs[index++].second;
        // }

        // 排序worker能力
        sort(worker.begin(), worker.end(), greater<int>());
        
        int sum = 0;
        int workerIndex = 0;
        int jobIndex = 0;
        while (workerIndex < worker.size()) {
            // 沒有能做的工作了
            if (jobIndex == jobs.size()) {
                break;
            }
            // 能勝任
            if (worker[workerIndex] >= jobs[jobIndex].second) {
                sum += jobs[jobIndex].first;
                workerIndex++;
            }
            // 太難，降低難度
            else {
                jobIndex++;
            }
        }
        return sum;
    }
};

#ifdef DEBUG
int main() {
    Solution s;
    vector<int> difficulty = {85,47,57};
    vector<int> profit = {24,66,99};
    vector<int> worker = {40,25,25};
    int ans = s.maxProfitAssignment(difficulty, profit, worker);
    return 0;
}
#endif
// @lc code=end

