/*
 * @lc app=leetcode.cn id=95 lang=cpp
 *
 * [95] 不同的二叉搜索树 II
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
    vector<TreeNode *> generateTrees(int n)
    {
        vector<TreeNode *> ans;
        return ans = n == 0 ? ans : Tree(1, n);
    }
    vector<TreeNode *> Tree(int l, int r)
    {
        if (l > r)
            return {nullptr};
        vector<TreeNode *> allans;
        for (int i = l; i <= r; i++)
        {
            vector<TreeNode *> lefttree = Tree(l, i - 1);
            vector<TreeNode *> righttree = Tree(i + 1, r);
            for (auto le : lefttree)
            {
                for (auto ri : righttree)
                {
                    TreeNode *root = new TreeNode(i);
                    root->left = le;
                    root->right = ri;
                    allans.push_back(root);
                }
            }
        }
        return allans;
    }
};
// @lc code=end

