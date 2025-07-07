/*
 * @lc app=leetcode id=1448 lang=cpp
 *
 * [1448] Count Good Nodes in Binary Tree
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
    int ans = 0;
    int goodNodes(TreeNode* root) {
        // DFS，過程紀錄目前路徑的最大值
        dfs(root, -INT_MAX);
        return ans;
    }

    void dfs(TreeNode* node, int maxValue) {
        if (!node) return;

        if (node->val >= maxValue)
            ans++;
        maxValue = max(maxValue, node->val) ;
        dfs(node->left, maxValue);
        dfs(node->right, maxValue);
    }
};
// @lc code=end

