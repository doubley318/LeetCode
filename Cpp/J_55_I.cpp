#include <iostream>
#include <math.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    int res = 0;
    void dfs(TreeNode *root, int deep)
    {
        if (root == nullptr)
        {
            res = max(res, deep);
            return;
        }
        dfs(root->left, deep + 1);
        dfs(root->right, deep + 1);
    }
    int maxDepth(TreeNode *root)
    {
        dfs(root, 0);
        return res;
    }
};

int main()
{
    return 0;
}