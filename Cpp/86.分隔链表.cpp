/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
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
    ListNode* partition(ListNode* head, int x) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *ans = new ListNode();
        ans->next = head;
        ListNode *l = ans;
        ListNode *r = ans;
        while (l && r)
        {
            while (l->next && l->next->val < x)
                l = l->next;
            r = l;
            while (r->next && r->next->val >= x)
                r = r->next;
            if (l->next && r->next)
            {
                ListNode *tmp = r->next;
                r->next = r->next->next;
                tmp->next = l->next;
                l->next = tmp;
            }
            l = l->next;
        }
        return ans->next;
    }
};
// @lc code=end

