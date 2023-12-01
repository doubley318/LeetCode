/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */

// @lc code=start

// Definition for singly-linked list.
/*struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
*/
/*
Solution so;
    int l1[3] = {2, 4, 3};
    int l2[3] = {5, 6, 4};
    ListNode *L1 = new ListNode();
    ListNode *L2 = new ListNode();
    ListNode *tmp1 = L1;
    ListNode *tmp2 = L2;
    for (int i = 0; i < 3; i++)
    {
        tmp1->val = l1[i];
        tmp2->val = l2[i];
        if (i + 1 < 3)
        {
            tmp1->next = new ListNode();
            tmp2->next = new ListNode();
            tmp1 = tmp1->next;
            tmp2 = tmp2->next;
        }
    }
    ListNode *res = so.addTwoNumbers(L1, L2);
*/
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *res = new ListNode();
        ListNode *tmp = res;
        int mark = 0;
        int a = 0;
        while (l1 || l2 || mark)
        {
            a = l1->val + l2->val + mark;
            mark = a / 10;
            if (mark == 0)
                tmp->val = a;
            else
                tmp->val = a % 10;
            if ((l1->next && l2->next) || mark)
            {
                tmp->next = new ListNode();
                tmp = tmp->next;
            }
            else
            {
                if (l1->next)
                    tmp->next = l1->next;
                else if (l2->next)
                    tmp->next = l2->next;
                return res;
            }
            if (l1->next)
                l1 = l1->next;
            else
                l1->val = 0;
            if (l2->next)
                l2 = l2->next;
            else
                l2->val = 0;
        }
        return res;
    }
};
// @lc code=end
