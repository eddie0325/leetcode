// from Neetcode
class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        vector<bool> visited(n, false);
        int count = 0;
        for (auto edge: edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        for(int i = 0; i < n; i++) {
            if (!visited[i]) {
                count++;
                dfs(i, visited, graph);
            }
        }
        return count;
    }

    void dfs(int cur, vector<bool>& visited, vector<vector<int>>& graph) {
        visited[cur] = true;
        for (auto& neighbor: graph[cur]) {
            if (!visited[neighbor]) {
                dfs(neighbor, visited, graph);
            }
        }
    }
};
