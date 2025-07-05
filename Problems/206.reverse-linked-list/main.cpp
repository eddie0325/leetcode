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
        ListNode *now = head;
        ListNode *last = nullptr;
        
        while(now != nullptr) {
            ListNode *next = now->next;
            now->next = last;
            last = now;
            now = next;
        }
        return last;
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

