/*
 * @lc app=leetcode id=2816 lang=cpp
 *
 * [2816] Double a Number Represented as a Linked List
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

#define DEBUG

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
    ListNode* doubleIt(ListNode* head) {
        // reverse
        ListNode* newListHead = reverseList(head);

        // double
        ListNode* currNode = newListHead;
        int carry = 0;
        while(currNode != nullptr) {
            currNode->val *= 2;
            // 來自低位數的進位
            currNode->val += carry;
            carry = currNode->val / 10;
            currNode->val %= 10;

            // for next
            currNode = currNode->next;
        }

        newListHead = reverseList(newListHead);
        
        // 有多一位出來
        if (carry > 0) {
            currNode = new ListNode(carry);
            currNode->next = newListHead;
            newListHead = currNode;
        }

        return newListHead;
    }

    // Problem 206: Reverse Linked List
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
    Solution s;
    Solution::ListNode* head = new Solution::ListNode(6);
    head->next = new Solution::ListNode(8);
    head->next->next = new Solution::ListNode(9);
    Solution::ListNode* res =s.doubleIt(head);
    return 0;
}
#endif
// @lc code=end

