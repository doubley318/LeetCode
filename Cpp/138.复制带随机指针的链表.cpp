/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 复制带随机指针的链表
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (head == nullptr)
            return nullptr;
        Node *res = new Node(head->val);
        Node *old_head = head->next;
        Node *new_head = res;
        while (old_head != nullptr)
        {
            Node *tmp = new Node(old_head->val);
            new_head->next = tmp;
            old_head = old_head->next;
            new_head = new_head->next;
        }
        old_head = head;
        new_head = res;
        while (old_head != nullptr)
        {
            Node *tmp = old_head->random;
            Node *tmp_old = head;
            Node *tmp_new = res;
            while (tmp_old != nullptr && tmp_old != tmp)
            {
                tmp_old = tmp_old->next;
                tmp_new = tmp_new->next;
            }
            new_head->random = tmp_new;
            old_head = old_head->next;
            new_head = new_head->next;
        }
        return res;
    }
};
// @lc code=end
