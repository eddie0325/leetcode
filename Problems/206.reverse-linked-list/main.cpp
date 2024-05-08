/*
 * @lc app=leetcode id=206 lang=cpp
 *
 * [206] Reverse Linked List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// #define DEBUG

class Solution {
public:

#ifdef DEBUG
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
#endif

    ListNode* reverseList(ListNode* head) {
        ListNode* prevNode = nullptr;
        ListNode* currNode = head;
        while(currNode != nullptr) {
            // 暫存下一個
            ListNode* nextNode = currNode->next;
            // 將下一個指向上一個
            currNode->next = prevNode;
            
            // for next
            prevNode = currNode;
            currNode = nextNode;
        }
        return prevNode;
    }
};

#ifdef DEBUG
int main() {
    Solution::ListNode* head = new Solution::ListNode(1);
    head->next = new Solution::ListNode(2);
    head->next->next = new Solution::ListNode(3);
    head->next->next->next = new Solution::ListNode(4);
    Solution s;
    auto res = s.reverseList(head);
    return 0;
}
#endif
// @lc code=end

