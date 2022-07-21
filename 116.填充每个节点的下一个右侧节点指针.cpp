/*
 * @lc app=leetcode.cn id=116 lang=cpp
 *
 * [116] 填充每个节点的下一个右侧节点指针
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node *connect(Node *root)
    {
        Node *head = root;
        if (!root)
            return head;
        while (root->left)
        {
            Node *tmp = root->left;
            while (root->next)
            {
                root->left->next = root->right;
                root->right->next = root->next->left;
                root = root->next;
            }
            root->left->next = root->right;
            root = tmp;
        }
        return head;
    }
};
// @lc code=end

