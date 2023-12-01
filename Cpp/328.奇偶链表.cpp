/*
 * @lc app=leetcode.cn id=328 lang=cpp
 *
 * [328] 奇偶链表
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
    ListNode *oddEvenList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *tmp = head;
        int length = 1;
        while (tmp->next)
        {
            tmp = tmp->next;
            length++;
        }
        ListNode *h = head;
        for (int i = 0; i < length / 2 && h->next != tmp; i++)
        {
            ListNode *t = h->next;
            h->next = t->next;
            h = h->next;
            tmp->next = t;
            tmp = tmp->next;
            tmp->next = nullptr;
        }
        return head;
    }
};
// @lc code=end
