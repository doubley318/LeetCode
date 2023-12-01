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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        if (preorder.size() == 0)
            return nullptr;
        TreeNode *root = new TreeNode(preorder[0]);
        int i = 0;
        for (; i < inorder.size(); i++)
            if (inorder[i] == preorder[0])
                break;
        vector<int> prel;
        vector<int> prer;
        vector<int> inl;
        vector<int> inr;
        for (int j = 0; j < i; j++)
        {
            prel.push_back(preorder[j + 1]);
            inl.push_back(inorder[j]);
        }
        for (int j = i + 1; j < inorder.size(); j++)
        {
            prer.push_back(preorder[j]);
            inr.push_back(inorder[j]);
        }
        root->left = buildTree(prel, inl);
        root->right = buildTree(prer, inr);
        return root;
    }
};