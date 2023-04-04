#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int val;
    Node *left;
    Node *right;

    Node() {}

    Node(int _val)
    {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node *_left, Node *_right)
    {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution
{
public:
    Node *pre;
    Node *head;
    void dfs(Node *cur)
    {
        if (cur == nullptr)
            return;
        dfs(cur->left);
        if (pre == nullptr)
            head = cur;
        else
            pre->right = cur;
        cur->left = pre;
        pre = cur;
        dfs(cur->right);
    }

    Node *treeToDoublyList(Node *root)
    {
        if (root == nullptr)
            return nullptr;
        dfs(root);
        head->left = pre;
        pre->right = head;
        return head;
    }
};

int main()
{
    return 0;
}