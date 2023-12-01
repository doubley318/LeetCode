/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层序遍历 II
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
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (!root)
            return ans;
        queue<TreeNode *> que;
        que.push(root);
        while (!que.empty())
        {
            int count = que.size();
            vector<int> smallans;
            while (count)
            {
                TreeNode *t = que.front();
                if (t->left)
                    que.push(t->left);
                if (t->right)
                    que.push(t->right);
                smallans.push_back(t->val);
                que.pop();
                count--;
            }
            ans.push_back(smallans);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end
