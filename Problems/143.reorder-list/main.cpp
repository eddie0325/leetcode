/*
 * @lc app=leetcode id=143 lang=cpp
 *
 * [143] Reorder List
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
class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return;
        // 分成前半跟後半
        // 後半reverse
        // 再merge

        // 1. 找中點
        ListNode *fast = head;
        ListNode *slow = head;
        while(fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *second = slow->next;
        slow->next = nullptr; // 分割

        // 將second做reverse
        ListNode *currentNode = second;
        ListNode *lastNode = nullptr;
        while(currentNode != nullptr) {
            ListNode *nextNode = currentNode->next;
            currentNode->next = lastNode;
            lastNode = currentNode;
            currentNode = nextNode;
        }
        second = lastNode;

        // merge first second
        ListNode *first = head;
        while(second != nullptr) {
            ListNode *temp1 = first->next;
            ListNode *temp2 = second->next;
            first->next = second;
            second->next = temp1;
            first = temp1;
            second = temp2;
        }
    }
};
// @lc code=end

