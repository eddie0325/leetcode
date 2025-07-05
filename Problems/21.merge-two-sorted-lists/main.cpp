/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *dummyNode = new ListNode(-1);
        ListNode *currentNode = dummyNode;

        while(list1 != nullptr && list2 != nullptr) {
            if (list1->val > list2->val) {
                currentNode->next = list2;
                list2 = list2->next;
            }
            else {
                currentNode->next = list1;
                list1 = list1->next;
            }
            currentNode = currentNode->next;
        }
        currentNode->next = (list1 == nullptr) ? list2 : list1;
        return dummyNode->next;
    }
};
// @lc code=end

