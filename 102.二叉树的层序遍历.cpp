/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> ret;
        queue<TreeNode *> que;
        if (root == nullptr)
            return ret;
        que.push(root);
        while (!que.empty())
        {
            int t = que.size();
            vector<int> ceng;
            for (int i = 0; i < t; i++)
            {
                TreeNode *tmp = que.front();
                if (tmp->left)
                    que.push(tmp->left);
                if (tmp->right)
                    que.push(tmp->right);
                ceng.push_back(tmp->val);
                que.pop();
            }
            ret.push_back(ceng);
        }
        return ret;
    }
};
// @lc code=end
