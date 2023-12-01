/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
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
    int target;
    vector<vector<int>> ans;

    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        if (!root)
            return ans;
        target = targetSum;
        small(root, 0, {});
        return ans;
    }

    void small(TreeNode *root, int sum, vector<int> tmp)
    {
        sum += root->val;
        tmp.push_back(root->val);
        if (!root->left && !root->right)
        {
            if (sum == target)
                ans.push_back(tmp);
            return;
        }
        if (root->right)
            small(root->right, sum, tmp);
        if (root->left)
            small(root->left, sum, tmp);
    }
};
// @lc code=end

