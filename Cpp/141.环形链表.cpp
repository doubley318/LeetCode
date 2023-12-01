/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        while (head)
        {
            if (head->val == INT_MAX)
                return true;
            head->val = INT_MAX;
            head = head->next;
        }
        return false;
    }
};
// @lc code=end

