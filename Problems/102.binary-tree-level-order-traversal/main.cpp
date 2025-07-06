/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        // DFS
        // travelTree(root, 0, ans);
        
        // BFS
        if (!root) return ans;
        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);
        int depth = 0;
        while(!nodeQueue.empty()) {
            // 一次處理一個level的node
            int levelSize = nodeQueue.size();
            vector<int> nodeArray;
            while(levelSize--) {
                auto node = nodeQueue.front();
                nodeQueue.pop();
                nodeArray.push_back(node->val);
                if (node->left)
                    nodeQueue.push(node->left);
                if (node->right)
                    nodeQueue.push(node->right);
            }
            ans.push_back(nodeArray);
        }

        return ans;
    }

    void travelTree(TreeNode* node, int depth, vector<vector<int>> &ans) {
        if (!node) return;
        if (ans.size() <= depth)
            ans.push_back({});
        ans[depth].push_back(node->val);
        travelTree(node->left, depth+1, ans);
        travelTree(node->right, depth+1, ans);
    }
};
// @lc code=end

