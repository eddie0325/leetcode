/*
 * @lc app=leetcode id=230 lang=cpp
 *
 * [230] Kth Smallest Element in a BST
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
    int kthSmallest(TreeNode* root, int k) {
        // inorder 左中右
        // 計數達到k結束
        int visitedCount = 0;
        int ans = -1;
        inorder(root, visitedCount, k, ans);
        return ans;
    }

    void inorder(TreeNode* node, int &visitedCount, int k, int &ans) {
        if (!node) return;

        // 左
        inorder(node->left, visitedCount, k, ans);

        // 中
        if (++visitedCount == k) {
            ans = node->val;
            return;
        }
        // 右
        inorder(node->right, visitedCount, k, ans);
    }
};
// @lc code=end

