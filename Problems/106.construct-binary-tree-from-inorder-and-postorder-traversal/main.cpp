/*
 * @lc app=leetcode id=106 lang=cpp
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
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
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    // inorder: 左中右 postorder: 左右中
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildSubTree(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }
    
    TreeNode* buildSubTree(vector<int>& inorder, int inorderStart, int inorderEnd, vector<int>& postorder, int postorderStart, int postorderEnd) {
        if (inorderStart > inorderEnd || postorderStart > postorderEnd) {
            return nullptr;
        }
        
        TreeNode* root = new TreeNode(postorder[postorderEnd]);
        for (int i = inorderStart; i <= inorderEnd; i++) {
            if (inorder[i] == root->val) {
                int leftNodeCout = i - inorderStart;
                int rightNodeCout = inorderEnd - i;
                if (leftNodeCout != 0) {
                    root->left = buildSubTree(inorder, inorderStart, inorderStart + leftNodeCout - 1, postorder, postorderStart, postorderStart + leftNodeCout - 1);
                }
                if (rightNodeCout != 0) {
                    root->right = buildSubTree(inorder, inorderStart + leftNodeCout + 1, inorderEnd, postorder, postorderStart + leftNodeCout, postorderEnd - 1);
                }
                break;
            }
        }
        return root;
    }
    
};

// For debug
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

// int main() {
//     Solution solution;
//     vector<int> inorder = {9,3,15,20,7};
//     vector<int> postorder = {9,15,7,20,3};
//     auto root = solution.buildTree(inorder, postorder);
//     cout << "root: " << root->val << endl;
//     return 0;
// }

// @lc code=end

