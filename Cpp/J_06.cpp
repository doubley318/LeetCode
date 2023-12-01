#include "mylib.h"
class Solution
{
public:
    vector<int> reversePrint(ListNode *head)
    {
        vector<int> tmp(10000);
        int n = 0;
        while (head)
        {
            tmp[n] = head->val;
            head = head->next;
            n++;
        }
        vector<int> res(n);
        for (int i = 0; i < n; i++)
        {
            res[i] = tmp[n - i - 1];
        }
        return res;
    }
};
int main()
{
    return 0;
}