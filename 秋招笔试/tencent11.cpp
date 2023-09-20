#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int x)
        : val(x)
        , left(nullptr)
        , right(nullptr)
    {
    }
};

class Solution {
public:
    int res = 0;
    void diff(TreeNode* root, int d)
    {
        if (root == nullptr) {
            return;
        }
        if (root->val == 1) {
            d++;
        } else {
            d--;
        }
        if (root->left == nullptr && root->right == nullptr) {
            if (d == 1) {
                res++;
            }
            return;
        }
        if (root->left != nullptr) {
            diff(root->left, d);
        }
        if (root->right != nullptr) {
            diff(root->right, d);
        }
    }

    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 返回节点权值1个数比0的个数多一的路径数
     * @param root TreeNode类 权值为0和1的二叉树根节点
     * @return int整型
     */
    int pathNumber(TreeNode* root)
    {
        diff(root, 0);
        return res;
    }
};

int main()
{
    Solution so;
    return 0;
}