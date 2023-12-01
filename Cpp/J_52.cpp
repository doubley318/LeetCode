#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr){};
    ListNode(int x) : val(x), next(nullptr){};
};

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *fast = headA;
        ListNode *slow = headB;
        while (fast != slow)
        {
            fast = fast == nullptr ? headB : fast->next;
            slow = slow == nullptr ? headA : slow->next;
        }
        return fast;
    }
};

int main()
{

    return 0;
}