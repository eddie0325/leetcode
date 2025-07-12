/*
 * @lc app=leetcode id=124 lang=cpp
 *
 * [124] Binary Tree Maximum Path Sum
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
    int maxSum = -INT_MAX;
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return maxSum;
    }

    int dfs(TreeNode* root) {
        if (!root) return 0;
        // 對每個node來說
        // 左中右可能會出現最大值
        // 提供給父節點左中或右中
        int leftMax = max(0, dfs(root->left));
        int rightMax = max(0, dfs(root->right));
        maxSum = max(maxSum, leftMax + rightMax + root->val);
        return max(leftMax + root->val, rightMax + root->val);
    }
};
// @lc code=end

