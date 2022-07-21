/*
 * @lc app=leetcode.cn id=965 lang=cpp
 *
 * [965] 单值二叉树
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
    bool isUnivalTree(TreeNode *root)
    {
        if (!root)
            return true;
        bool ans = true;
        if (root->left)
        {
            if (root->val == root->left->val)
                ans = isUnivalTree(root->left);
            else
                return false;
        }
        if (!ans)
            return false;
        if (root->right)
        {
            if (root->val == root->right->val)
                ans = isUnivalTree(root->right);
            else
                return false;
        }
        return ans;
    }
};
// @lc code=end
