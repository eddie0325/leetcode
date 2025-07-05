/*
 * @lc app=leetcode id=138 lang=cpp
 *
 * [138] Copy List with Random Pointer
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // if (head == nullptr) return nullptr;
        // unordered_map<Node*, Node*> nodeMap;
        
        // Node *currentNode = head;

        // while(currentNode != nullptr) {
        //     Node *newNode = new Node(currentNode->val);
        //     nodeMap[currentNode] = newNode;
        //     currentNode = currentNode->next;
        // }
        // currentNode = head;
        // while(currentNode != nullptr) {
        //     Node *newNode = nodeMap[currentNode];
        //     // next
        //     Node *nextNode = currentNode->next;
        //     Node *nextNewNode = (nextNode != nullptr) ? nodeMap[nextNode] : nullptr;
        //     newNode->next = nextNewNode;

        //     // random
        //     Node *randomNode = currentNode->random;
        //     Node *randomNewNode = (randomNode != nullptr) ? nodeMap[randomNode] : nullptr;
        //     newNode->random = randomNewNode;

        //     currentNode = currentNode->next;
        // }
        // return nodeMap[head];

        // inplace
        // 複製每個節點插在原節點之後
        Node *currentNode = head;
        while(currentNode != nullptr) {
            Node *newNode = new Node(currentNode->val);
            newNode->next = currentNode->next;
            currentNode->next = newNode;
            currentNode = newNode->next;
        }
        // 設定Random
        currentNode = head;
        while(currentNode != nullptr) {
            Node *newNode = currentNode->next;
            if (currentNode->random != nullptr)
                newNode->random = currentNode->random->next;
            currentNode = currentNode->next->next;
        }
        // 抽離
        Node dummyNode = Node(0);
        Node *newCurrentNode = &dummyNode;
        currentNode = head;
        while(currentNode != nullptr) {
            newCurrentNode->next = currentNode->next;
            currentNode->next = currentNode->next->next;
            newCurrentNode = newCurrentNode->next;
            currentNode = currentNode->next;
        }
        Node *result = dummyNode.next;
        return result;
    }
};
// @lc code=end

