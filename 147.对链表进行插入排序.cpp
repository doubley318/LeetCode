/*
 * @lc app=leetcode.cn id=147 lang=cpp
 *
 * [147] 对链表进行插入排序
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
    ListNode *insertionSortList(ListNode *head)
    {
        ListNode *vir_head = new ListNode();
        vir_head->next = new ListNode(head->val);
        ListNode *tmp = head->next;
        while (tmp != nullptr)
        {
            ListNode *t = tmp;
            tmp = tmp->next;
            ListNode *i = vir_head;
            while (i->next != nullptr)
            {
                if (i->next->val <= t->val)
                {
                    i = i->next;
                    if (i->next == nullptr)
                    {
                        i->next = t;
                        t->next = nullptr;
                    }
                }
                else
                {
                    ListNode *j = i->next;
                    i->next = t;
                    t->next = j;
                    break;
                }
            }
        }
        return vir_head->next;
    }
};
// @lc code=end
