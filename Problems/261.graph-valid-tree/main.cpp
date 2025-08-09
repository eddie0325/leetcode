// from Neetcode
class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        // tree 邊數 = 節點 -1
        if (edges.size() != n - 1) return false;

        vector<bool> visited(n, false);
        vector<vector<int>> graph(n);
        for (auto& edge: edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        if (hasCycle(-1, 0, visited, graph)) return false;

        // 確認所有節點都有拜訪
        for (int i = 0; i < n; i++)
            if (!visited[i]) return false;
        return true;
    }

    bool hasCycle(int parent, int cur, vector<bool>& visited, vector<vector<int>>& graph) {
        visited[cur] = true;
    
        for (int neighbor: graph[cur]) {
            if (!visited[neighbor]) {
                if (hasCycle(cur, neighbor, visited, graph))
                    return true;
            }
            else if (neighbor != parent) // 拜訪過且不是上個點
                return true;
        }
        return false;
    }
};
