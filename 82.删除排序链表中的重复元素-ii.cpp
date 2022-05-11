/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] 删除排序链表中的重复元素 II
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

// 如果打算l直接连接r的话很可能就是做不出来，但是因为r是重复的，直到
// r != r->next，然后l->next = r->next 但是l不动。
class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *ans = new ListNode();
        ans->next = head;
        ListNode *l = ans;
        ListNode *r = head;
        while (r)
        {
            while (r->next && r->val == r->next->val)
                r = r->next;
            if (l->next == r)
                l = l->next;
            else
                l->next=r->next;
            r=r->next;
        }
        return ans->next;
    }
};
// @lc code=end
