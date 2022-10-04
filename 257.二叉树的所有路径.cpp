/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
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
    vector<string> pre;
    void binaryTreePaths(TreeNode *root, string s)
    {
        if (root == nullptr)
            return;
        s = s + to_string(root->val);
        if (root->left == nullptr && root->right == nullptr)
        {
            pre.push_back(s);
            return;
        }
        s = s + "->";
        binaryTreePaths(root->left, s);
        binaryTreePaths(root->right, s);
        return;
    }

    vector<string> binaryTreePaths(TreeNode *root)
    {
        binaryTreePaths(root, "");
        return pre;
    }
};
// @lc code=end
