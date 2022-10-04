/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
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
    bool isPalindrome(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return true;
        ListNode *fast = head;
        ListNode *slow = head;
        ListNode *pre = nullptr;
        while (fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            ListNode *tmp = slow;
            slow = slow->next;
            tmp->next = pre;
            pre = tmp;
        }
        if (fast != nullptr)
            slow = slow->next;
        while (slow != nullptr)
        {
            if (slow->val != pre->val)
                return false;
            else
            {
                slow = slow->next;
                pre = pre->next;
            }
        }
        return true;
    }
};
// @lc code=end
