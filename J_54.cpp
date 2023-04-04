#include <iostream>
#include <vector>
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
    int myk, res;
    void dfs(TreeNode *root)
    {
        if (root == nullptr || myk <= 0)
            return;
        dfs(root->right);
        myk--;
        if (myk == 0)
            res = root->val;
        dfs(root->left);
    }

    int kthLargest(TreeNode *root, int k)
    {
        myk = k;
        dfs(root);
        return res;
    }
};

int main()
{
    return 0;
}