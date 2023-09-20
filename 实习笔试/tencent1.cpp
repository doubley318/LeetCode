#include <iostream>
#include <vector>
using namespace std;

struct ListNode
{
    int val;
    struct ListNode *next;
    // ListNode(int a = 0) : val(a){};
};

ListNode *makeListNode(vector<int> nums)
{
    ListNode *head = new ListNode();
    ListNode *tmp = head;
    for (int i = 0; i < nums.size(); i++)
    {
        ListNode *t = new ListNode;
        t->val = nums[i];
        tmp->next = t;
        tmp = tmp->next;
    }
    tmp->next = nullptr;
    return head->next;
}

class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * @param head ListNode类
     * @return ListNode类
     */
    ListNode *reorderList(ListNode *head)
    {
        ListNode *visul_head = (ListNode *)malloc(sizeof(ListNode));
        visul_head->next = head;
        ListNode *pre = visul_head;
        while (pre != nullptr && pre->next != nullptr && pre->next->next != nullptr && pre->next->next->next != nullptr)
        {
            ListNode *node1 = pre->next;
            ListNode *node2 = node1->next;
            ListNode *node3 = node2->next;
            ListNode *node4 = nullptr;
            ListNode *node5 = nullptr;
            if (node3 != nullptr)
                node4 = node3->next;
            if (node4 != nullptr)
                node5 = node4->next;
            pre->next = node3;
            if (node4 != nullptr)
            {
                node4->next = node1;
                node2->next = node5;
            }
            else
            {
                node3->next = node1;
                node2->next = nullptr;
            }
            pre = node2;
        }
        return visul_head->next;
    }
};

int main()
{
    Solution so;
    vector<int> nums{1, 2, 3, 4, 5, 6};
    ListNode *head = makeListNode(nums);
    head = so.reorderList(head);
    while (head)
    {
        cout << head->val << " ";
        head = head->next;
    }
    return 0;
}