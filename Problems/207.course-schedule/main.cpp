/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 */

// @lc code=start

// #define DEBUG

#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> edges(numCourses);
        vector<bool> passed(numCourses, false);
        vector<bool> needChecked(numCourses, false);

        for (auto &p : prerequisites) {
            edges[p[0]].push_back(p[1]);
            needChecked[p[1]] = true;
        }

        for (int i = 0; i < numCourses; ++i) {
            // 只檢查有前置條件的
            if (!needChecked[i]) {
                continue;
            }
            vector<int> visited;
            if (hasCycle(i, visited, passed, edges)) {
                return false;
            }
        }
        return true;
    }

    bool hasCycle(int start, vector<int> visited, vector<bool> &passed, vector<vector<int>> &edges) {
        // 已經檢查過了
        if (passed[start]) {
            return false;
        }

        visited.push_back(start);
        for(auto v: edges[start]) {
            // 已經造訪過了
            if (find(visited.begin(), visited.end(), v) != visited.end()) {
                return true;
            }
            // 遍歷子代
            if (hasCycle(v, visited, passed, edges)) {
                return true;
            }
        }
        passed[start] = true;
        return false;
    }
};

#ifdef DEBUG
int main() {
    Solution s;
    int numCourses = 3;
    vector<vector<int>> prerequisites = {{0,1},{0,2},{1,2}};
    bool ans = s.canFinish(numCourses, prerequisites);
    return 0;
}
#endif
// @lc code=end

