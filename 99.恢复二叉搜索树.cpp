/*
 * @lc app=leetcode.cn id=99 lang=cpp
 *
 * [99] 恢复二叉搜索树
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
class Solution {
public:
    TreeNode *x = nullptr;
    TreeNode *y = nullptr;
    TreeNode *pre = nullptr;
    void recoverTree(TreeNode *root)
    {
        insorted(root);
        if (x && y)
            swap(x->val, y->val);
    }

    void insorted(TreeNode *root)
    {
        if (!root)
            return;
        insorted(root->left);
        if (!pre)
            pre = root;
        else
        {
            if (pre->val > root->val)
            {
                y = root;
                if (!x)
                    x = pre;
            }
            pre = root;
        }
        insorted(root->right);
    }
};
// @lc code=end

