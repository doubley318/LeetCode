/*
 * @lc app=leetcode.cn id=2807 lang=cpp
 *
 * [2807] 在链表中插入最大公约数
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
    ListNode* insertGreatestCommonDivisors(ListNode* head)
    {
        ListNode* ret = head;
        ListNode* tmp = head->next;
        while (tmp != nullptr) {
            head->next = new ListNode(__gcd(head->val, tmp->val), tmp);
            head = tmp;
            tmp = head->next;
        }
        return ret;
    }
};
// @lc code=end
