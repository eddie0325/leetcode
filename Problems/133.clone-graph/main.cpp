/*
 * @lc app=leetcode id=133 lang=cpp
 *
 * [133] Clone Graph
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> nodeMap;
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        
        if (nodeMap.find(node) != nodeMap.end()) {
            return nodeMap[node];
        }

        Node* newNode = new Node(node->val);
        nodeMap[node] = newNode;
        for (auto neighbor: node->neighbors) {
            newNode->neighbors.push_back(cloneGraph(neighbor));
        }
        return newNode;
    }
};
// @lc code=end

