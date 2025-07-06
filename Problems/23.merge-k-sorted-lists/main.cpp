/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
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
    struct compare {
        bool operator()(ListNode *a, ListNode *b) {
            return a->val > b->val;
        } 
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> minHeap;
        for (auto list: lists) {
            if (list)
                minHeap.push(list);
        }
        ListNode *dummyNode = new ListNode(0);
        ListNode *currentNode = dummyNode;
        while(!minHeap.empty()) {
            ListNode *minNode = minHeap.top();
            minHeap.pop();
            currentNode->next = minNode;
            currentNode = currentNode->next;

            if (minNode->next)
                minHeap.push(minNode->next);
        }
        ListNode *result = dummyNode->next;
        delete dummyNode;
        return result;
    }
};
// @lc code=end

