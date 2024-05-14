/*
 * @lc app=leetcode id=110 lang=cpp
 *
 * [110] Balanced Binary Tree
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

// #define DEBUG

using namespace std;
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

    bool isBalanced(TreeNode* root) {
        if (root == nullptr) return true;
        int left = getHeight(root->left);
        int right = getHeight(root->right);
        // 自己滿足且子代也滿足
        return abs(left - right) <= 1 &&isBalanced(root->left) && isBalanced(root->right);
    }

    int getHeight(TreeNode* root) {
        if (root == nullptr) return 0;
        int left = getHeight(root->left);
        int right = getHeight(root->right);
        return 1 + max(left, right);
    }


    
};

#ifdef DEBUG
int main() {
    Solution s;
    Solution::TreeNode* root = new Solution::TreeNode(1);
    root->left = new Solution::TreeNode(2);
    root->right = new Solution::TreeNode(2);
    root->left->left = new Solution::TreeNode(3);
    root->left->right = new Solution::TreeNode(3);
    root->left->left->left = new Solution::TreeNode(4);
    root->left->left->right = new Solution::TreeNode(4);
    bool a = s.isBalanced(root);
    return 0;
}
#endif
// @lc code=end

