/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if (head == nullptr)
            return nullptr;
        ListNode *res = head;
        ListNode *tmp = head;
        ListNode *t = nullptr;
        for (int i = 0; i < n; i++)
            tmp = tmp->next;
        while (tmp)
        {
            t = res;
            tmp = tmp->next;
            res = res->next;
        }
        if (t == nullptr)
            return head->next ? head->next : nullptr;
        t->next = res->next;
        return head;
    }
};
// @lc code=end

