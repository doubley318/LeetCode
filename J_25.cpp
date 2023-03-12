#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr){};
    ListNode(int a) : val(a), next(nullptr){};
};

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        if (l1 == nullptr)
            return l2;
        ListNode *head1 = new ListNode();
        ListNode *head2 = new ListNode();
        head1->next = l1;
        head2->next = l2;
        ListNode *p1 = head1;
        ListNode *p2 = head2;
        while (p1->next && p2->next)
        {
            if (p1->next->val >= p2->next->val)
            {
                ListNode *tmp = p1->next;
                p1->next = p2->next;
                p2->next = p2->next->next;
                p1->next->next = tmp;
                p1 = p1->next;
            }
            else
            {
                p1 = p1->next;
            }
        }
        if (p2->next)
            p1->next = p2->next;
        return head1->next;
    }
};

int main()
{

    return 0;
}