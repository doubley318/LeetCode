/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *list = new ListNode();
        ListNode *form = list;
        list->next = head;
        while (head)
        {
            if (head->val == val)
                form->next = head->next;
            else
                form = form->next;
            head = head->next;
        }
        return list->next;
    }
};
// @lc code=end

