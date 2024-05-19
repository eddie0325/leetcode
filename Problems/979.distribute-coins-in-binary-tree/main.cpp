/*
 * @lc app=leetcode id=979 lang=cpp
 *
 * [979] Distribute Coins in Binary Tree
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


#define DEBUG

#include <stdlib.h>

class Solution {
public:
#ifdef DEBUG
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };
#endif

    int distributeCoins(TreeNode* root) {
        return dfs(root);
    }

    int dfs(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }
        // bottom-top dfs
        int move = dfs(node->left) + dfs(node->right);

        // 以leaf為出發點，讓每個leaf都變成1
        if (node->left != nullptr) {
            int extraCoin =  node->left->val - 1;
            node->left->val = 1;
            node->val += extraCoin;
            move += abs(extraCoin); 
        }
        if (node->right != nullptr) {
            int extraCoin =  node->right->val - 1;
            node->right->val = 1;
            node->val += extraCoin;
            move += abs(extraCoin); 
        }
        return move;
    }
};

#ifdef DEBUG
int main() {
    Solution s;
    Solution::TreeNode* root = new Solution::TreeNode(0);
    root->left = new Solution::TreeNode(3);
    root->right = new Solution::TreeNode(0);
    int res = s.distributeCoins(root);
    return 0;
}
#endif
// @lc code=end

