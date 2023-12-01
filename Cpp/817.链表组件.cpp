/*
 * @lc app=leetcode.cn id=817 lang=cpp
 *
 * [817] 链表组件
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
    int numComponents(ListNode *head, vector<int> &nums)
    {
        unordered_set<int> num;
        for (int i = 0; i < nums.size(); i++)
            num.insert(nums[i]);
        int ret = 0, mark = 0;
        ListNode *tmp = new ListNode();
        tmp->next = head;
        while (tmp->next != nullptr)
        {
            if (mark == 0)
            {
                if (num.find(tmp->next->val) != num.end())
                {
                    ret++;
                    mark = 1;
                }
            }
            else
            {
                if (num.find(tmp->next->val) == num.end())
                    mark = 0;
            }
            tmp = tmp->next;
        }
        return ret;
    }
};
// @lc code=end
