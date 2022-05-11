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
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode *> que;
        if (root == nullptr)
            return ans;
        que.push(root);
        while (!que.empty())
        {
            vector<int> tmp;
            int count = que.size();
            while (count)
            {
                TreeNode *t = que.front();
                if (t->left)
                    que.push(t->left);
                if (t->right)
                    que.push(t->right);
                tmp.push_back(t->val);
                que.pop();
                count--;
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};
// @lc code=end

