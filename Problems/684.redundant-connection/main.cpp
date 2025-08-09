/*
 * @lc app=leetcode id=684 lang=cpp
 *
 * [684] Redundant Connection
 */

// @lc code=start
// #KEYPOINT Disjoint set
class Solution {
public:
    class UnionFind {
    public:
        vector<int> size;
        vector<int> parent;

        UnionFind(int n) {
            size.resize(n, 1);
            parent.resize(n);
            for (int i = 0; i < n; i++)
                parent[i] = i;
        }

        int find(int x) {
            if (parent[x] != x)
                parent[x] = find(parent[x]);
            return parent[x];
        }

        bool unite(int x, int y) {
            int rootX = find(x);
            int rootY = find(y);
            if (rootX == rootY) // 已經同集合
                return false;
            if (size[rootX] < size[rootY]){
                parent[rootX] = rootY;
                size[rootY] += size[rootX];
            }
                
            else {
                parent[rootY] = rootX;
                size[rootX] += size[rootY];
            }
            return true;
        }
    };

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        UnionFind djs(edges.size() + 1);

        for(auto edge: edges) {
            if (!djs.unite(edge[0], edge[1]))
                return edge;
        }
        return {};
    }
};
// @lc code=end

