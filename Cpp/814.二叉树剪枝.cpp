/*
 * @lc app=leetcode.cn id=814 lang=cpp
 *
 * [814] 二叉树剪枝
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
    TreeNode *pruneTree(TreeNode *root)
    {
        smallpruneTree(root);
        if (root->left == nullptr && root->right == nullptr && root->val == 0)
            return nullptr;
        return root;
    }

    bool smallpruneTree(TreeNode *root)
    {
        if (root == nullptr)
            return true;
        bool l = smallpruneTree(root->left);
        bool r = smallpruneTree(root->right);
        if (l == true)
            root->left = nullptr;
        if (r == true)
            root->right = nullptr;
        if (l == false || r == false || root->val == 1)
            return false;
        return true;
    }
};
// @lc code=end
