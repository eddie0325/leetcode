/*
 * @lc app=leetcode id=210 lang=cpp
 *
 * [210] Course Schedule II
 */

// @lc code=start
// #KEYPOINT Topological Ordering
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);
        for (auto& prerequisite: prerequisites) {
            int from = prerequisite[1];
            int to = prerequisite[0];
            indegree[to]++;
            graph[from].push_back(to);
        }

        queue<int> q;
        vector<int> ans;

        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        while(!q.empty()) {
            int pre = q.front();
            q.pop();
            ans.push_back(pre);

            for (int next: graph[pre]) {
                indegree[next]--;
                if (indegree[next] == 0) q.push(next);
            }
        }
        if (ans.size() != numCourses)
            return {};
        return ans;
    }
};
// @lc code=end

