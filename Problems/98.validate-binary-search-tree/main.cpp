/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
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
    bool isValidBST(TreeNode* root) {
        return dfs(root, -LLONG_MAX, LLONG_MAX);
    }

    bool dfs(TreeNode* node, long long minValue, long long maxValue) {
        if (!node) return true;
        if (node->val <= minValue || node->val >= maxValue)
            return false;
        // 左子樹所有所有節點都<node，反之亦然
        bool leftCheck = dfs(node->left, minValue, node->val);
        bool rightCheck = dfs(node->right, node->val, maxValue);
        return leftCheck && rightCheck;
    }
};
// @lc code=end

