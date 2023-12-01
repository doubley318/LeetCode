#include <iostream>
#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr){};
    TreeNode(int v, TreeNode *l, TreeNode *r) : val(v), left(l), right(r){};
};

class Solution
{
public:
    int mytarget;
    vector<vector<int>> res;
    void mySum(TreeNode *root, int tmp, vector<int> tmp_res)
    {
        tmp_res.push_back(root->val);
        tmp = tmp + root->val;
        if (root->left == nullptr && root->right == nullptr)
        {
            if (tmp == mytarget)
            {
                res.push_back(tmp_res);
            }
            return;
        }
        if (root->left)
            mySum(root->left, tmp, tmp_res);
        if (root->right)
            mySum(root->right, tmp, tmp_res);
    }

    vector<vector<int>> pathSum(TreeNode *root, int target)
    {
        if (root == nullptr)
            return res;
        mytarget = target;
        vector<int> tmp_res;
        mySum(root, 0, tmp_res);
        return res;
    }
};

int main()
{
    return 0;
}