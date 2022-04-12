/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
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
    /*
    Your runtime beats 100 % of cpp submissions
    Your memory usage beats 5.01 % of cpp submissions (10.2 MB)
        vector<int> preorderTraversal(TreeNode *root)
        {
            vector<int> ans;
            ans = preroot(root, ans);
            return ans;
        }

        vector<int> preroot(TreeNode *root, vector<int> &ans)
        {
            if (root)
                ans.push_back(root->val);
            else
                return ans;
            preroot(root->left, ans);
            preroot(root->right, ans);
            return ans;
        }
    */

    // Your runtime beats 40.25 % of cpp submissions
    // Your memory usage beats 43.47 % of cpp submissions (8.2 MB)
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        if (root == nullptr)
            return ans;
        stack<TreeNode *> st;
        st.push(root);
        while (!st.empty())
        {
            root = st.top();
            ans.push_back(root->val);
            st.pop();
            if (root->right != nullptr)
                st.push(root->right);
            if (root->left != nullptr)
                st.push(root->left);
        }
        return ans;
    }
};
// @lc code=end
