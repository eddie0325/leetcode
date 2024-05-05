/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
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
#include <vector>
#include <iostream>
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
    // preorder: 中左右 inorder: 左中右
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildSubTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
    
    TreeNode* buildSubTree(vector<int>& preorder, int preorderStart, int preorderEnd, vector<int>& inorder, int inorderStart, int inorderEnd) {
        if (preorderStart > preorderEnd || inorderStart > inorderEnd) {
            return nullptr;
        }
        
        TreeNode* root = new TreeNode(preorder[preorderStart]);
        for (int i = inorderStart; i <= inorderEnd; i++) {
            if (inorder[i] == root->val) {
                int leftNodeCout = i - inorderStart;
                int rightNodeCout = inorderEnd - i;
                if (leftNodeCout != 0) {
                    root->left = buildSubTree(preorder, preorderStart + 1, preorderStart + leftNodeCout, inorder, inorderStart, inorderStart + leftNodeCout - 1);
                }
                if (rightNodeCout != 0) {
                    root->right = buildSubTree(preorder, preorderStart + leftNodeCout + 1, preorderEnd, inorder, inorderStart + leftNodeCout + 1, inorderEnd);
                }
                break;
            }
        }
        return root;
    }
};

#ifdef DEBUG
int main() {
    Solution solution;
    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};
    auto root = solution.buildTree(preorder, inorder);
    cout << "root: " << root->val << endl;
    return 0;
}
#endif


// @lc code=end

