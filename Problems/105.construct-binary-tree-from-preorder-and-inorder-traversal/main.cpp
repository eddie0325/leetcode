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
    unordered_map<int, int> inorderMap;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // preorder: 中左右
        // inorder: 左中右

        // 預處理，之後搜尋root時O(1)
        for (int i = 0; i < inorder.size(); i++)
            inorderMap[inorder[i]] = i;

        return buildSubTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }

    TreeNode* buildSubTree(vector<int>& preorder, int preorderStart, int preorderEnd, vector<int>& inorder, int inorderStart, int inorderEnd) {
        if (preorderEnd < preorderStart) return nullptr;
        
        int rootValue = preorder[preorderStart];
        TreeNode* root = new TreeNode(rootValue);
        int rootIndex = inorderMap[rootValue];

        int leftNodeCount = rootIndex - inorderStart;
        root->left = buildSubTree(preorder, preorderStart + 1, preorderStart + leftNodeCount, inorder, inorderStart, rootIndex - 1);
        root->right = buildSubTree(preorder, preorderStart + leftNodeCount + 1, preorderEnd, inorder, rootIndex + 1, inorderEnd);
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

