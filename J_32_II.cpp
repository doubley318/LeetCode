#include "mylib.h"
class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        queue<TreeNode *> que;
        vector<vector<int>> res;
        if (root == nullptr)
            return res;
        que.push(root);
        while (!que.empty())
        {
            int count = que.size();
            vector<int> tmp;
            for (int i = 0; i < count; i++)
            {
                TreeNode *x = que.front();
                if (x->left)
                    que.push(x->left);
                if (x->right)
                    que.push(x->right);
                tmp.push_back(x->val);
                que.pop();
            }
            res.push_back(tmp);
        }
        return res;
    }
};

int main()
{
    return 0;
}