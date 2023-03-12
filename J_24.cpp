#include "mylib.h"

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *tmp = head->next;
        head->next = nullptr;
        while (tmp->next)
        {
            ListNode *t = tmp->next;
            tmp->next = head;
            head = tmp;
            tmp = t;
        }
        tmp->next = head;
        return tmp;
    }
};