/*
 * @lc app=leetcode id=212 lang=cpp
 *
 * [212] Word Search II
 */

// @lc code=start
class Solution {
public:
    struct TrieNode{
        TrieNode* child[26] = {nullptr};
        string word = "";
    };

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();
        vector<string> ans;
        for (int i = 0; i < words.size(); i++) {
            TrieNode* curNode = root;
            for (char c: words[i]) {
                if (!curNode->child[c - 'a'])
                    curNode->child[c - 'a'] = new TrieNode();
                curNode = curNode->child[c - 'a'];
            }
            curNode->word = words[i];
        }
        // 開始跑board dfs
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                TrieNode* curNode = root;
                char c = board[i][j];
                if (!root->child[c - 'a']) continue;
                board[i][j] = '#';
                dfs(board, ans, i, j, root->child[c - 'a']);
                board[i][j] = c;
            }
        }
        deleteNode(root);
        return ans;
    }

    void dfs(vector<vector<char>>& board, vector<string> &ans, int row, int col, TrieNode* curNode) {
        if (curNode->word != "") {
            ans.push_back(curNode->word);
            curNode->word = "";
        }
        int dir[4][2] = {{1,0}, {-1, 0}, {0, 1}, {0, -1}};
        for (auto &d: dir) {
            int newRow = row + d[0];
            int newCol = col + d[1];
            if (newRow < board.size() && newRow >=0 && newCol < board[newRow].size() && newCol >=0) {
                char c = board[newRow][newCol];
                if (c != '#' && curNode->child[c - 'a']) {
                    board[newRow][newCol] = '#';
                    dfs(board, ans, newRow, newCol, curNode->child[c - 'a']);
                    board[newRow][newCol] = c;
                }
            }
        }
    }

    void deleteNode(TrieNode* node) {
        for (int i = 0; i < 26; i++) {
            if (node->child[i])
                deleteNode(node->child[i]);
        }
        delete node;
    }
};
// @lc code=end

