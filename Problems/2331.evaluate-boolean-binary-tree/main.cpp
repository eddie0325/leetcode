/*
 * @lc app=leetcode id=2331 lang=cpp
 *
 * [2331] Evaluate Boolean Binary Tree
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
 
    bool evaluateTree(TreeNode* root) {
        return calcTree(root);
    }

    bool calcTree(TreeNode* root) {
        if (root->val == 0 || root->val == 1) {
            return root->val == 1;
        }
        else if (root->val == 2) {
            return evaluateTree(root->left) || evaluateTree(root->right);
        }
        else if (root->val == 3) {
            return evaluateTree(root->left) && evaluateTree(root->right);
        }
        return false;
    }
};

#ifdef DEBUG
int main() {
    Solution s;
    Solution::TreeNode root = Solution::TreeNode(2);
    root.left = new Solution::TreeNode(1);
    root.right = new Solution::TreeNode(3);
    root.right->left = new Solution::TreeNode(0);
    root.right->right = new Solution::TreeNode(1);
    bool aaa = s.evaluateTree(&root);
    return 0;
}
#endif
// @lc code=end

