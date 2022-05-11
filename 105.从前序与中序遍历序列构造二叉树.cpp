/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        return smallTree(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }

    TreeNode *smallTree(vector<int> preorder, vector<int> inorder, int l_per, int r_per, int l_in, int r_in)
    {
        if (l_per > r_per)
            return nullptr;
        TreeNode *head = new TreeNode(preorder[l_per]);
        int m_in;
        for (int i = l_in; i <= r_in; i++)
        {
            if (inorder[i] == preorder[l_per])
            {
                m_in = i;
                break;
            }
        }
        head->left = smallTree(preorder, inorder, l_per + 1, l_per + m_in - l_in, l_in, m_in - 1);
        head->right = smallTree(preorder, inorder, l_per + m_in - l_in + 1, r_per, m_in + 1, r_in);
        return head;
    }
};
// @lc code=end

