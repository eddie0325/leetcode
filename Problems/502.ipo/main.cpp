/*
 * @lc app=leetcode id=502 lang=cpp
 *
 * [502] IPO
 */

// @lc code=start
// #KEYPOINT priority_queue(max heap)
// #define DEBUG
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
class Solution {
public:
    struct Project {
        int profit;
        int capital;    
    };

    struct compareProfit {
        bool operator()(Project a, Project b) {
            return a.profit < b.profit;
        }
    };

    struct compareCapital {
        bool operator()(Project a, Project b) {
            return a.capital < b.capital;
        }
    };

    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        int finished = 0;
        priority_queue<Project, vector<Project>, compareProfit> profitMaxHeap;
        vector<Project> projects;
        
        for (int i = 0; i < n; ++i) {
            Project project = {profits[i], capital[i]};
            projects.push_back(project);
        }
        // 根據capital排序
        sort(projects.begin(), projects.end(), compareCapital());
        
        int lastAdd = 0;
        while(finished < k){
            for (;lastAdd < n;) {
                if (projects[lastAdd].capital > w){
                    break;
                }
                profitMaxHeap.push(projects[lastAdd++]);
            }
            // 已經沒有人可以取了
            if (profitMaxHeap.empty()){
                break;
            }
            // 在可以選擇的project取最大的profit
            Project project = profitMaxHeap.top();
            profitMaxHeap.pop();
            w += project.profit;
            finished++;
        }
        return w;
    }
};
#ifdef DEBUG
int main() {
    Solution s;
    int k = 10;
    int w = 0;
    vector<int> profits = {1, 2, 3};
    vector<int> capital = {0, 1, 2};
    int ans = s.findMaximizedCapital(k, w, profits, capital);
    return 0;
}
#endif
// @lc code=end

