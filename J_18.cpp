#include <iostream>
#include <vector>
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
    ListNode *deleteNode(ListNode *head, int val)
    {
        ListNode *res = new ListNode();
        ListNode *pre = res;
        res->next = head;
        while (head)
        {
            if (head->val == val)
            {
                ListNode *tmp = head->next;
                pre->next = tmp;
                return res->next;
            }
            head = head->next;
            pre = pre->next;
        }
        return res->next;
    }
};

int main()
{
    return 0;
}
