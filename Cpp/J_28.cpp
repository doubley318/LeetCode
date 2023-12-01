#include "mylib.h"

class Solution
{
public:
    bool isSymmetric(TreeNode *root)
    {
        if (root == nullptr)
            return true;
        queue<TreeNode *> queA;
        queue<TreeNode *> queB;
        queA.push(root);
        queB.push(root);
        while (!queA.empty())
        {
            int tmp = queA.size();
            for (int i = 0; i < tmp; i++)
            {
                TreeNode *tA = queA.front();
                TreeNode *tB = queB.front();
                if (tA->left && tB->right)
                {
                    queA.push(tA->left);
                    queB.push(tB->right);
                }
                else if (tA->left || tB->right)
                {
                    return false;
                }
                if (tA->right && tB->left)
                {
                    queA.push(tA->right);
                    queB.push(tB->left);
                }
                else if (tA->right || tB->left)
                {
                    return false;
                }
                if (tA->val != tB->val)
                    return false;
                queA.pop();
                queB.pop();
            }
        }
        return true;
    }
};

int main()
{
    return 0;
}