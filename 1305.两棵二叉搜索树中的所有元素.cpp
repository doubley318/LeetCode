/*
 * @lc app=leetcode.cn id=1305 lang=cpp
 *
 * [1305] 两棵二叉搜索树中的所有元素
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
    vector<int> getAllElements(TreeNode *root1, TreeNode *root2)
    {
        vector<int> tmp1 = morris(root1);
        vector<int> tmp2 = morris(root2);
        vector<int> ans;
        int l = 0, r = 0;
        while (l < tmp1.size() && r < tmp2.size())
        {
            if (tmp1[l] < tmp2[r])
                ans.push_back(tmp1[l]), l++;
            else
                ans.push_back(tmp2[r]), r++;
        }
        while (l < tmp1.size())
            ans.push_back(tmp1[l]), l++;
        while (r < tmp2.size())
            ans.push_back(tmp2[r]), r++;
        return ans;
    }

    vector<int> morris(TreeNode *root)
    {
        vector<int> ans;
        while (root)
        {
            while (root->left)
            {
                TreeNode *tmp = root->left;
                while (tmp->right)
                {
                    tmp = tmp->right;
                }
                tmp->right = root;
                TreeNode *t = root->left;
                root->left = nullptr;
                root = t;
            }
            ans.push_back(root->val);
            root = root->right;
        }
        return ans;
    }
};
// @lc code=end

