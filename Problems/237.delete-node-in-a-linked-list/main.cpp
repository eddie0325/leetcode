/*
 * @lc app=leetcode id=237 lang=cpp
 *
 * [237] Delete Node in a Linked List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// #define DEBUG
class Solution {
public:

#ifdef DEBUG
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(nullptr) {}
    };
#endif

    void deleteNode(ListNode* node) {
        // next都不變，只有val改變
        // 依序遍歷改變val
        ListNode* nowNode = node;
        while(1) {
            nowNode -> val = nowNode -> next -> val;
            // 如果下一個Node是Linked list的最末點
            if (nowNode -> next -> next == nullptr) {
                nowNode -> next = nullptr;
                break;
            }
            nowNode = nowNode -> next;
        }
    }
};

#ifdef DEBUG
int main() {
    Solution::ListNode* head = new Solution::ListNode(1);
    head -> next = new Solution::ListNode(2);
    head -> next -> next = new Solution::ListNode(3);
    head -> next -> next -> next = new Solution::ListNode(4);
    head -> next -> next -> next -> next = new Solution::ListNode(5);
    
    Solution s;
    s.deleteNode(head -> next);
    
    return 0;
}
#endif

// @lc code=end

