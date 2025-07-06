/*
 * @lc app=leetcode id=25 lang=cpp
 *
 * [25] Reverse Nodes in k-Group
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        auto dummyNode = new ListNode(0);
        dummyNode->next = head;
        auto groupPre = dummyNode;

        while(true) {
            // 確認足不足k
            auto groupEnd = groupPre;
            for (int i = 0; i < k && groupEnd != nullptr; i++) {
                groupEnd = groupEnd->next;
            }
            if (groupEnd == nullptr)
                break;

            // reverse group
            auto groupStart = groupPre->next;
            auto nextGroupStart = groupEnd->next;
            reverseNodes(groupStart, groupEnd);
            // 把新的 group 接起來
            auto newHead = groupEnd;
            auto newTail = groupStart;
            groupPre->next = newHead;
            newTail->next = nextGroupStart;
            groupPre = newTail;
        }
        auto result = dummyNode->next;
        delete dummyNode;
        return result;
    }

    void reverseNodes(ListNode* start, ListNode* end) {
        ListNode* last = nullptr;
        auto curr = start;
        while(true) {
            auto next = curr->next;
            curr->next = last;
            if (curr == end) break;
            last = curr;
            curr = next;
        }
    }
};
// @lc code=end

