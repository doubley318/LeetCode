/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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
    bool hasPathSum(TreeNode* root, int targetSum) {
        stack<TreeNode *> sta;
        if (root == nullptr)
            return false;
        sta.push(root);
        while (!sta.empty())
        {
            root = sta.top();
            sta.pop();
            if (root->val == targetSum && root->left == nullptr && root->right == nullptr)
                return true;
            if (root->left)
            {
                root->left->val += root->val;
                sta.push(root->left);
            }
            if (root->right)
            {
                root->right->val += root->val;
                sta.push(root->right);
            }
        }
        return false;
    }
};
// @lc code=end

