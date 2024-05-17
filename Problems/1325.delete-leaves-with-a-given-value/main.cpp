/*
 * @lc app=leetcode id=1325 lang=cpp
 *
 * [1325] Delete Leaves With a Given Value
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
    TreeNode* removeLeafNodes(TreeNode* node, int target) {
        removeChildNode(node, target);

        // 如果最後只剩根且＝target
        if (node->val == target && node->left == nullptr && node->right == nullptr) {
            node = nullptr;
        }
        return node;
    }

    bool removeChildNode(TreeNode* node, int target) {
        if (node == nullptr) {
            return true;
        }
        // 檢查left
        bool removeLeft = false;
        if (node->left == nullptr || removeChildNode(node->left, target)) {
            node->left = nullptr;
            removeLeft = true;
        }

        // 檢查right
        bool removeRight = false;
        if (node->right == nullptr || removeChildNode(node->right, target)) {
            node->right = nullptr;
            removeRight = true;
        }
        // 都符合條件，此點應該要delete
        return removeLeft && removeRight && node->val == target;
    }

};

#ifdef DEBUG
int main() {
    Solution s;
    Solution::TreeNode* root = new Solution::TreeNode(1);
    root->left = new Solution::TreeNode(2);
    root->right = new Solution::TreeNode(3);
    root->left->left = new Solution::TreeNode(2);
    root->right->left = new Solution::TreeNode(2);
    root->right->right = new Solution::TreeNode(4);

    auto aaa = s.removeLeafNodes(root, 2);
    return 0;
}
#endif
// @lc code=end

