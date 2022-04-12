/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
    ListNode *swapPairs(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *res = new ListNode();
        res->next = head;
        ListNode *l1 = res;
        while (l1)
        {
            if (l1->next)
            {
                ListNode *l2 = l1->next;
                if (l2->next)
                {
                    ListNode *l3 = l2->next;
                    ListNode *l4 = l3->next;
                    l1->next = l3;
                    l3->next = l2;
                    l2->next = l4;
                }
                else
                    break;
            }
            else
                break;
            l1 = l1->next->next;
        }
        return res->next;
    }
};
// @lc code=end
