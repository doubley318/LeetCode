/*
 * @lc app=leetcode.cn id=230 lang=cpp
 *
 * [230] 二叉搜索树中第K小的元素
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
    int t = 0;
    int ret = 0;

public:
    void dfs(TreeNode *root)
    {
        if (t == 0 || root == nullptr)
            return;
        dfs(root->left);
        t--;
        if (t == 0 && ret == 0)
            ret = root->val;
        dfs(root->right);
    }

    int kthSmallest(TreeNode *root, int k)
    {
        t = k;
        dfs(root);
        return ret;
    }
};
// @lc code=end
