/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
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
    int res = INT_MIN;

    int maxSum(TreeNode* root)
    {
        if (root->left == nullptr && root->right == nullptr) {
            res = max(res, root->val);
            return root->val;
        }
        int l = INT_MIN, r = INT_MIN;
        if (root->left != nullptr) {
            l = maxSum(root->left);
        }
        if (root->right != nullptr) {
            r = maxSum(root->right);
        }
        res = max(root->val, max(l + r + root->val, (l + root->val, r + root->val)));
        root->val = max(root->val, max(l, r) + root->val);
        return root->val;
    }
    int maxPathSum(TreeNode* root)
    {
        maxSum(root);
        return res;
    }
};
// @lc code=end
