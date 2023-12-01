/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> res;
        stack<TreeNode *> statree;
        if (root == nullptr)
            return res;
        TreeNode *tmp = root;
        while (!statree.empty() || tmp != nullptr)
        {
            if (tmp != nullptr)
            {
                statree.push(tmp);
                tmp = tmp->left;
            }
            else
            {
                res.push_back(statree.top()->val);
                tmp = statree.top()->right;
                statree.pop();
            }
        }
        return res;
    }
};
// @lc code=end

