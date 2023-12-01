#include "mylib.h"

class Solution
{
public:
    bool same(TreeNode *A, TreeNode *B)
    {
        if (B == nullptr)
            return true;
        if (A == nullptr)
            return false;
        return (A->val == B->val) && same(A->left, B->left) && same(A->right, B->right);
    }

    bool isSubStructure(TreeNode *A, TreeNode *B)
    {
        if (B == nullptr || A == nullptr)
            return false;
        if (A->val == B->val)
            if (same(A, B))
                return true;
        return isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }
};

int main()
{
    return 0;
}