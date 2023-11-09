/*
 * @lc app=leetcode.cn id=1171 lang=cpp
 *
 * [1171] 从链表中删去总和值为零的连续节点
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
    ListNode *removeZeroSumSublists(ListNode *head)
    {
        int sum = 0;
        unordered_map<int, ListNode *> tmp;
        vector<int> SUM;
        ListNode *virhead = new ListNode(0);
        tmp[0] = virhead;
        SUM.push_back(0);
        virhead->next = head;
        while (head != nullptr)
        {
            sum += head->val;
            tmp[sum] = head;
            SUM.push_back(sum);
            head = head->next;
        }
        head = virhead;
        int point = 0;
        bool RES = true;
        while (head != nullptr)
        {
            if (tmp.find(SUM[point]) != tmp.end() && tmp[SUM[point]] != head)
            {
                head->next = tmp[SUM[point]]->next;
                RES = false;
                break;
            }
            head = head->next;
            point++;
        }
        if (RES)
            return virhead->next;
        return removeZeroSumSublists(virhead->next);
    }
};
// @lc code=end
