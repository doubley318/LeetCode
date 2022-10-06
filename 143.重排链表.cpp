/*
 * @lc app=leetcode.cn id=143 lang=cpp
 *
 * [143] 重排链表
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
    ListNode *reverseList(ListNode *head)
    {
        if (head->next == nullptr)
            return head;
        ListNode *tmp_head = head;
        head = head->next;
        tmp_head->next = nullptr;
        while (head->next != nullptr)
        {
            ListNode *tmp;
            tmp = head->next;
            head->next = tmp_head;
            tmp_head = head;
            head = tmp;
        }
        head->next = tmp_head;
        return head;
    }

    void reorderList(ListNode *head)
    {
        int amount = 0;
        ListNode *tmp_head = head;
        while (tmp_head != nullptr)
        {
            tmp_head = tmp_head->next;
            amount++;
        }
        if (amount <= 2)
            return;
        tmp_head = head;
        int l = amount - amount / 2;
        while (l > 0)
        {
            tmp_head = tmp_head->next;
            l--;
        }
        tmp_head = reverseList(tmp_head);
        ListNode *tmp = head;
        while (tmp_head != nullptr)
        {
            ListNode *l_next = tmp->next;
            ListNode *r_next = tmp_head->next;
            tmp->next = tmp_head;
            tmp_head->next = l_next;
            tmp = l_next;
            tmp_head = r_next;
        }
        if (tmp != nullptr)
            tmp->next = nullptr;
    }
};
// @lc code=end

