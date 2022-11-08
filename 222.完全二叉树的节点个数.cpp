/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
 */

// @lc code=start
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
class Solution
{
public:
    int countNodes(TreeNode *root)
    {
        int floor = 1;
        if (root == nullptr)
            return 0;
        TreeNode *tmp = root;
        while (tmp != nullptr)
        {
            if (tmp->left)
                tmp = tmp->left;
            else
                break;
            floor++;
        }
        int left = pow(2, floor - 1);
        int right = pow(2, floor) - 1;
        while (left < right)
        {
            int mid = (right - left + 1) / 2 + left;
            int t = 1 << (floor - 2);
            tmp = root;
            while (t != 0)
            {
                if (mid & t)
                    tmp = tmp->right;
                else
                    tmp = tmp->left;
                t = t >> 1;
            }
            if (tmp == nullptr)
                right = mid - 1;
            else
                left = mid;
        }
        return left;
    }
};
// @lc code=end
