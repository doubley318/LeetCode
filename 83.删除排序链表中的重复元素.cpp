/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
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
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *l = head;
        ListNode *r = head->next;
        while (r != nullptr)
        {
            if (r->val != l->val)
            {
                l->next = r;
                l = r;
            }
            r = r->next;
        }
        l->next = nullptr;
        return head;
    }
};
// @lc code=end

