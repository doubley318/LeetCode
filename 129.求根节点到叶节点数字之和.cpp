/*
 * @lc app=leetcode.cn id=129 lang=cpp
 *
 * [129] 求根节点到叶节点数字之和
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
    int sumNumbers(TreeNode *root)
    {
        int ret = 0;
        queue<TreeNode *> que;
        que.push(root);
        while (!que.empty())
        {
            TreeNode *tmp = que.front();
            que.pop();
            if (tmp->left)
            {
                tmp->left->val += tmp->val * 10;
                que.push(tmp->left);
            }
            if (tmp->right)
            {
                tmp->right->val += tmp->val * 10;
                que.push(tmp->right);
            }
            if (tmp->left == nullptr && tmp->right == nullptr)
                ret += tmp->val;
        }
        return ret;
    }
};
// @lc code=end

