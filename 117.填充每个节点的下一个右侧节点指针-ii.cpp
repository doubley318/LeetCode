/*
 * @lc app=leetcode.cn id=117 lang=cpp
 *
 * [117] 填充每个节点的下一个右侧节点指针 II
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
    Node* connect(Node* root)
    {
        Node* head = root;
        Node* rootNode = new Node();
        bool Visited = true;
        while (Visited) {
            Visited = false;
            Node* preNode = rootNode;
            for (; head != nullptr; head = head->next) {
                if (head->left) {
                    preNode->next = head->left;
                    preNode = preNode->next;
                    Visited = true;
                }
                if (head->right) {
                    preNode->next = head->right;
                    preNode = preNode->next;
                    Visited = true;
                }
            }
            head = rootNode->next;
        }
        return root;
    }
};
// @lc code=end
