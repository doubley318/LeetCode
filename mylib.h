#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <queue>
#include <math.h>
#include <map>
#include <set>
#include <unordered_map>
#include <bitset>
#include <algorithm>
#include <climits>
#include <unordered_set>
#include <random>
#include <time.h>

using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Definition for a Node.
struct Node
{
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

struct DLinkedNode
{
    int key, value;
    DLinkedNode *prev;
    DLinkedNode *next;
    DLinkedNode() : key(0), value(0), prev(nullptr), next(nullptr) {}
    DLinkedNode(int _key, int _value) : key(_key), value(_value), prev(nullptr), next(nullptr) {}
};

/*struct Node
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
};*/

// Make the binary tree.
TreeNode *make_tree(int a[], int size)
{
    TreeNode *root = new TreeNode(a[0]);
    queue<TreeNode *> s;
    s.push(root);
    for (int i = 0; i < size / 2 && (!s.empty()); i++)
    {
        TreeNode *mark_left = a[i * 2 + 1] == 0 ? NULL : (new TreeNode(a[i * 2 + 1]));
        TreeNode *mark_right = a[i * 2 + 2] == 0 ? NULL : (new TreeNode(a[i * 2 + 2]));
        TreeNode *mark = s.front();
        mark->left = mark_left;
        mark->right = mark_right;
        if (mark_left != NULL)
            s.push(mark_left);
        if (mark_right != NULL)
            s.push(mark_right);
        s.pop();
    }
    return root;
}

/*
Node *make_tree(int a[], int size)
{
    Node *root = new Node(a[0]);
    queue<Node *> s;
    s.push(root);
    for (int i = 0; i < (size / sizeof(a[0])) / 2 && (!s.empty()); i++)
    {
        Node *mark_left = a[i * 2 + 1] == 0 ? NULL : (new Node(a[i * 2 + 1]));
        Node *mark_right = a[i * 2 + 2] == 0 ? NULL : (new Node(a[i * 2 + 2]));
        Node *mark = s.front();
        mark->left = mark_left;
        mark->right = mark_right;
        if (mark_left != NULL)
            s.push(mark_left);
        if (mark_right != NULL)
            s.push(mark_right);
        s.pop();
    }
    return root;
}*/

// Make the singly-link
ListNode *make_list(int a[], int size)
{
    ListNode *root = new ListNode(a[0]);
    ListNode *node = root;
    for (int i = 1; i < size; i++)
    {
        ListNode *mark = new ListNode(a[i]);
        node->next = mark;
        node = node->next;
    }
    return root;
}
