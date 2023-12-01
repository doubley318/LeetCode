/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *r = head;
        int count = 1;
        while (r->next)
            r = r->next, count++;
        r->next = head;
        for (int i = 0; i < count - k % count; i++)
            r = r->next;
        head = r->next;
        r->next = nullptr;
        return head;
    }
};
// @lc code=end

