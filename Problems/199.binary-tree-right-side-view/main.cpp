/*
 * @lc app=leetcode id=199 lang=cpp
 *
 * [199] Binary Tree Right Side View
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
    vector<int> rightSideView(TreeNode* root) {
        // 每個level最後一個
        // 用queue先進先出，跑BFS
        queue<TreeNode*> levelQueue;
        vector<int> ans;

        if (!root) return ans;

        levelQueue.push(root);

        while(!levelQueue.empty()) {
            TreeNode* node = nullptr;
            int size = levelQueue.size();
            while(size--) {
                node = levelQueue.front();
                levelQueue.pop();
                if (node->left)
                    levelQueue.push(node->left);
                if (node->right)
                    levelQueue.push(node->right);
            }
            ans.push_back(node->val);
        }
        return ans;
    }
};
// @lc code=end

