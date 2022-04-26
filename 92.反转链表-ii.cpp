/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
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
class Solution
{
public:
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        ListNode *ans = new ListNode();
        ans->next = head;
        ListNode *l = ans;
        ListNode *r = ans;
        int flag = 0;
        int count = 1;
        while (r)
        {
            if (count == left)
                break;
            else
                l = l->next, r = r->next, count++;
        }
        if (r->next)
            r = r->next;
        while (count != right)
        {
            ListNode *tmp = r->next->next;
            r->next->next = l->next;
            l->next = r->next;
            r->next = tmp;
            count++;
        }
        return ans->next;
    }
};
// @lc code=end
