/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层序遍历
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root)
            return ans;
        bool up = true;
        deque<TreeNode *> deq;
        deq.push_back(root);
        while (!deq.empty())
        {
            int count = deq.size();
            vector<int> t;
            while (count)
            {
                if (up)
                {
                    TreeNode *tmp = deq.front();
                    if (tmp->left)
                        deq.push_back(tmp->left);
                    if (tmp->right)
                        deq.push_back(tmp->right);
                    t.push_back(tmp->val);
                    deq.pop_front();
                }
                else
                {
                    TreeNode *tmp = deq.back();
                    if (tmp->right)
                        deq.push_front(tmp->right);
                    if (tmp->left)
                        deq.push_front(tmp->left);
                    t.push_back(tmp->val);
                    deq.pop_back();
                }
                count--;
            }
            up = !up;
            ans.push_back(t);
        }
        return ans;
    }
};
// @lc code=end

