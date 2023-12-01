#include <iostream>
#include <vector>
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
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        int Max = max(p->val, q->val);
        int Min = min(p->val, q->val);
        while (root != nullptr)
        {
            if (root->val > Max)
                root = root->left;
            else if (root->val < Min)
                root = root->right;
            else
                break;
        }
        return root;
    }
};