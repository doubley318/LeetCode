/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个升序链表
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
    struct cmp
    {
        bool operator()(ListNode *a, ListNode *b)
        {
            return a->val > b->val;
        }
    };

    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        priority_queue<ListNode *, vector<ListNode *>, cmp> p;
        for (auto a : lists)
            if (a)
                p.push(a);
        ListNode *head = new ListNode();
        ListNode *tmp = head;
        while (!p.empty())
        {
            tmp->next = p.top();
            p.pop();
            tmp = tmp->next;
            if (tmp->next)
                p.push(tmp->next);
        }
        return head->next;
    }
};
// @lc code=end

