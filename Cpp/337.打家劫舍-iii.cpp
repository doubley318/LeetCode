/*
 * @lc app=leetcode.cn id=337 lang=cpp
 *
 * [337] 打家劫舍 III
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
    vector<int> small(TreeNode *root)
    {
        vector<int> ret(2, 0);
        if (root == nullptr)
            return ret;
        vector<int> left = small(root->left);
        vector<int> right = small(root->right);
        ret[0] = max(left[0], left[1]) + max(right[0], right[1]);
        ret[1] = root->val + left[0] + right[0];
        return ret;
    }

    int rob(TreeNode *root)
    {
        vector<int> ret = small(root);
        return max(ret[0], ret[1]);
    }
};
// @lc code=end
