#include "mylib.h"
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    vector<int> levelOrder(TreeNode *root)
    {
        queue<TreeNode *> que;
        vector<int> res;
        if (root == nullptr)
            return res;
        que.push(root);
        while (!que.empty())
        {
            int tmp = que.size();
            for (int i = 0; i < tmp; i++)
            {
                TreeNode *t = que.front();
                que.pop();
                res.push_back(t->val);
                if (t->left)
                    que.push(t->left);
                if (t->right)
                    que.push(t->right);
            }
        }
        return res;
    }
};
int main()
{
    return 0;
}