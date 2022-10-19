/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
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
    vector<int> rightSideView(TreeNode *root)
    {

        vector<int> ret;
        if (root == nullptr)
            return ret;
        queue<TreeNode *> que;
        que.push(root);
        ret.push_back(root->val);
        while (!que.empty())
        {
            int i = que.size();
            while (i > 0)
            {
                TreeNode *tmp = que.front();
                if (tmp->left != nullptr)
                    que.push(tmp->left);
                if (tmp->right != nullptr)
                    que.push(tmp->right);
                que.pop();
                i--;
            }
            if (!que.empty())
                ret.push_back(que.back()->val);
        }
        return ret;
    }
};
// @lc code=end
