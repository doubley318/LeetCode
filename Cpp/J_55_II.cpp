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
    bool res = true;
    bool isBalanced(TreeNode *root)
    {
        dfs(root);
        return res;
    }

    int dfs(TreeNode *root)
    {
        if (!res || root == nullptr)
            return 0;
        int l = dfs(root->left);
        int r = dfs(root->right);
        if (abs(l - r) >= 2)
            res = false;
        return max(l, r) + 1;
    }
};

int main()
{
    return 0;
}