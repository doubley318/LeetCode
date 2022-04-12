/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        return postroot(root, ans);
    }

    vector<int> postroot(TreeNode *root, vector<int> &ans)
    {
        if (root == nullptr)
            return ans;
        postroot(root->left, ans);
        postroot(root->right, ans);
        ans.push_back(root->val);
        return ans;
    }
};
// @lc code=end

