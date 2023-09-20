#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int val;
    Node* pre;
    Node* next;
    Node()
        : val(0)
        , next(nullptr)
        , pre(nullptr) {};
    Node(int v)
        : val(v)
        , next(nullptr)
        , pre(nullptr) {};
};

int main()
{
    int a;
    Node* root = new Node();
    Node* tmp = root;
    while (cin >> a) {
        tmp->next = new Node(a);
        tmp->next->pre = tmp;
        tmp = tmp->next;
    }

    Node* pre = root->next;
    tmp = pre->next;
    Node* ne = tmp->next;
    while (pre != nullptr && ne != nullptr) {
        if (pre->val + tmp->val == ne->val) {
            pre->next = ne;
            ne->pre = pre;
            tmp = ne;
            Node* pre_pre = pre->pre;
            while (pre_pre != root) {
                if (pre_pre->val + pre->val == tmp->val) {
                    pre_pre->next = tmp;
                    tmp->pre = pre_pre;
                    pre = pre_pre;
                    pre_pre = pre_pre->pre;
                } else {
                    break;
                }
            }
        } else {
            pre = pre->next;
            tmp = tmp->next;
        }
        ne = ne->next;
    }

    ne = root->next;
    while (ne != nullptr) {
        cout << ne->val << " ";
        ne = ne->next;
    }
    return 0;
}