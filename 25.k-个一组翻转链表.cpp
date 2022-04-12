/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        stack<ListNode *> sta;
        ListNode *res = new ListNode();
        res->next=head;
        ListNode *tmp = res;
        while (tmp)
        {
            ListNode *c = tmp->next;
            int i = 0;
            for (; i < k && c; i++)
            {
                sta.push(c);
                c = c->next;
            }
            if (i < k)
                break;
            while (!sta.empty())
            {
                tmp->next = sta.top();
                sta.pop();
                tmp = tmp->next;
            }
            tmp->next = c;
        }
        return res->next;
    }
};
// @lc code=end

