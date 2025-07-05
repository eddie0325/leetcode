/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // ListNode* currentNode = head;
        // int size = 0;
        // while(currentNode != nullptr) {
        //     currentNode = currentNode->next;
        //     size++;
        // }
        // if (size == n) return head->next;

        // // 1 2 3 4 5   1 2 3 5
        // // 5 2.    3
        // int indexFromBegin = size - n;
        // int index = 1;
        // currentNode = head;
        // for (int i = 1; i < indexFromBegin; i++)
        //     currentNode = currentNode->next;
        // currentNode->next = currentNode->next->next;
        // return head;

        // 利用slow fast pointer 一次遍歷
        // 0 1 2 3 4 5   n = 2
        // 1 2 3 5
        // s   f
        // 
        ListNode *dummyNode = new ListNode(0);
        dummyNode->next = head;
        ListNode *slow = dummyNode;
        ListNode *fast = dummyNode;

        // fast先往前走n步
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }
        // 在同步一起走直到盡頭
        while(fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        // slow下一個就是要刪除的對象
        slow->next = slow->next->next;
        ListNode *result = dummyNode->next;
        delete dummyNode;
        return result;
    }
};
// @lc code=end

