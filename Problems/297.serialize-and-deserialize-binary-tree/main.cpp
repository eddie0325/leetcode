/*
 * @lc app=leetcode id=297 lang=cpp
 *
 * [297] Serialize and Deserialize Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        // dfs + preorder
        // 用null來表示這空節點，這樣只靠preorder就能決定唯一樹
        if (!root) return "null,";
        return to_string(root->val) + "," + serialize(root->left) + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        string token;
        queue<string> q;
        while (getline(ss, token, ',')) {
            q.push(token);
        }
        return buildTree(q);
    }

    // "1,2,null,null,3,4,null,null,5,null,null,"

    TreeNode* buildTree(queue<string> &preorder) {
        string rootValue = preorder.front();
        preorder.pop();
        if (rootValue == "null") return nullptr;
        TreeNode* root = new TreeNode(stoi(rootValue));
        root->left = buildTree(preorder);
        root->right = buildTree(preorder);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end

