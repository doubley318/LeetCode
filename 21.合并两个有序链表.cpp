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
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr)
            return list2;
        else if (list2 == nullptr)
            return list1;
        ListNode *head;
        if (list1->val < list2->val)
        {
            head = list1;
            list1 = list2;
            list2 = head;
        }
        else
            head = list2;
        ListNode *tmp = head;
        ListNode *tmp2;
        while (list1 && list2)
        {
            if (list1->val >= list2->val && list2->next != nullptr)
            {
                if (list1->val <= list2->next->val)
                {
                    tmp = list1->next;
                    tmp2 = list2->next;
                    list2->next = list1;
                    list1->next = tmp2;
                    list1 = tmp;
                }
                else
                    list2 = list2->next;
            }
            else
            {
                list2->next = list1;
                break;
            }
        }
        return head;
    }
};
// @lc code=end

