/*
 * @lc app=leetcode.cn id=2487 lang=cpp
 *
 * [2487] 从链表中移除节点
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
    ListNode* removeNodes(ListNode* head)
    {
        // 单调栈
        stack<ListNode*> sta;
        while (head != nullptr) {
            if (sta.empty()) {
                sta.push(head);
            } else {
                while (!sta.empty() && sta.top()->val < head->val) {
                    sta.pop();
                }
                sta.push(head);
            }
            head = head->next;
        }
        head = sta.top();
        head->next = nullptr;
        sta.pop();
        while (!sta.empty()) {
            sta.top()->next = head;
            head = sta.top();
            sta.pop();
        }
        return head;
    }
};
// @lc code=end
