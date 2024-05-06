/*
 * @lc app=leetcode id=2487 lang=cpp
 *
 * [2487] Remove Nodes From Linked List
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

#include <vector>
using namespace std;
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

    ListNode* removeNodes(ListNode* head) {
        // 將所有值存入vector中
        std::vector<int> values = {0};
        ListNode* nowNode = head;
        while(nowNode != nullptr) {
            values.push_back(nowNode->val);
            nowNode = nowNode->next;
        }

        // 每個元素 存以自身為右的最大值
        // 對應到list，如果不是該值就表示該node要被移除
        for (int i = values.size() - 1; i > 0; i--) {
            values[i] = values[i + 1] > values[i] ? values[i + 1] : values[i];
        }

        // 安插一個假head，來找出結果list的headnode
        // 0 13 13 13 8 8
        ListNode* tempHead = new ListNode(0);
        tempHead->next = head;
        return buildNewList(tempHead, values) -> next;

        // TLE
        /*
        // 先用一個假Node，來找出結果list的headnode
        ListNode* tempHead = new ListNode(0);
        tempHead->next = head;

        // 開始依序找出新list的子Node
        ListNode* nowNode = tempHead;
        while(1) {
            if (nowNode -> next == nullptr) {
                break;
            }
            nowNode -> next = findMaxValueNode(nowNode -> next);
            nowNode = nowNode -> next;
        }
        return tempHead -> next;
        */
    }

    ListNode* buildNewList(ListNode* head, vector<int> values) {
        int nowIndex = 0;
        ListNode* requiredNode = head;
        ListNode* nowNode = head;

        while(1) {
            int nextIndex = nowIndex + 1;
            ListNode* nextNode = nowNode->next;
            if (nextNode == nullptr) {
                break;
            }
            // 找到有對應vector值的node
            if (values[nextIndex] == nextNode->val) {
                requiredNode -> next = nextNode;
                requiredNode = requiredNode -> next;
            }
            nowNode = nextNode;
            nowIndex = nextIndex;
        }
        // 最後一個requiredNode的next指向nullptr
        requiredNode -> next = nullptr;

        return head;
    }

    // 找此List中最大的Node
    ListNode* findMaxValueNode(ListNode* head) {
        // Default
        ListNode* maxValueNode = head;
        int max = maxValueNode->val;

        ListNode* nowNode = maxValueNode;
        while(1) {
            ListNode* nextNode = nowNode->next;
            if (nextNode == nullptr) {
                break;
            }

            // 如果有找到新的最大值，就更新maxValueNode
            if (nextNode -> val > max) {
                max = nextNode->val;
                maxValueNode = nextNode;
            }

            nowNode = nextNode;
        }
        return maxValueNode;

    }
};

#ifdef DEBUG
int main() {
    Solution s;
    Solution::ListNode* head = new Solution::ListNode(5);
    head->next = new Solution::ListNode(2);
    head->next->next = new Solution::ListNode(13);
    head->next->next->next = new Solution::ListNode(3);
    head->next->next->next->next = new Solution::ListNode(8);
    Solution::ListNode* res = s.removeNodes(head);
    return 0;
}
#endif

// @lc code=end

