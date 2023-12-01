/*
 * @lc app=leetcode.cn id=109 lang=cpp
 *
 * [109] 有序链表转换二叉搜索树
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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head)
    {
        vector<int> array;
        while (head)
        {
            array.push_back(head->val);
            head = head->next;
        }
        return small(array, 0, array.size() - 1);
    }

    TreeNode *small(vector<int> array, int l, int r)
    {
        if (l > r)
            return nullptr;
        int m = (l + r) / 2;
        TreeNode *head = new TreeNode(array[m]);
        head->left = small(array, l, m - 1);
        head->right = small(array, m + 1, r);
        return head;
    }
};
// @lc code=end

