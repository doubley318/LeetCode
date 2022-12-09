/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *head = new ListNode();
        ListNode *tmp = head;
        while (list1 != nullptr && list2 != nullptr)
        {
            if (list1->val < list2->val)
            {
                tmp->next = list1;
                tmp = tmp->next;
                list1 = list1->next;
            }
            else
            {
                tmp->next = list2;
                tmp = tmp->next;
                list2 = list2->next;
            }
        }
        tmp->next = list1 == nullptr ? list2 : list1;
        return head->next;
    }
};
// @lc code=end
