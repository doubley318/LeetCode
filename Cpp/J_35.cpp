#include "mylib.h"

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        map<Node *, int> nodemap;
        Node *tmp = head;
        int n = 0;
        while (tmp)
        {
            nodemap[tmp] = n;
            n++;
            tmp = tmp->next;
        }
        tmp = head;
        Node *res = new Node(0);
        Node *tmp_res = res;
        map<int, Node *> resmap;
        n = 0;
        while (tmp)
        {
            Node *t = new Node(tmp->val);
            tmp_res->next = t;
            resmap[n] = t;
            tmp = tmp->next;
            tmp_res = tmp_res->next;
            n++;
        }
        tmp = head;
        tmp_res = res->next;
        while (tmp)
        {
            tmp_res->random = tmp->random == nullptr ? nullptr : resmap[nodemap[tmp->random]];
            tmp_res = tmp_res->next;
            tmp = tmp->next;
        }
        return res->next;
    }
};

int main()
{
    return 0;
}