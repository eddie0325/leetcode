/*
 * @lc app=leetcode id=543 lang=cpp
 *
 * [543] Diameter of Binary Tree
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
    int diameterOfBinaryTree(TreeNode* root) {
        int maxValue = 0;
        doDepth(root, maxValue);
        return maxValue;
    }

    int doDepth(TreeNode* node, int &maxValue) {
        // 計算以node為根的子樹，計算diameter並回傳深度
        if (!node) return 0;

        int leftDepth = doDepth(node->left, maxValue);
        int rightDepth = doDepth(node->right, maxValue);
        // 經過此節點的路徑長度 = 左子樹深度 + 右子樹深度
        maxValue = max(maxValue, leftDepth + rightDepth);
        // 回傳該節點深度
        return 1 + max(leftDepth, rightDepth);
    }
};
// @lc code=end

