/*
 * @lc app=leetcode id=211 lang=cpp
 *
 * [211] Design Add and Search Words Data Structure
 */

// @lc code=start
class WordDictionary {
public:
    struct TrieNode {
        TrieNode* child[26] = {nullptr};
        bool isEnd = false;
    };

    TrieNode* root;

    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* cur = root;
        for (char c: word) {
            if (!cur->child[c - 'a'])
                cur->child[c - 'a'] = new TrieNode();
            cur = cur->child[c - 'a'];
        }
        cur->isEnd = true;
    }
    
    bool search(string word) {
        return searchChar(word, 0, root);
    }

    bool searchChar(string &word, int index, TrieNode* curNode) {
        if (index == word.length())
            return curNode->isEnd;
        char c = word[index];
        if (c == '.') {
            for (int i = 0; i < 26; i++) {
                if (!curNode->child[i]) continue;
                if (searchChar(word, index + 1, curNode->child[i]))
                    return true;
            }
            return false;
        }
        else {
            if (!curNode->child[c - 'a'])
                return false;
            return searchChar(word, index + 1, curNode->child[c - 'a']);
        } 
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
// @lc code=end

