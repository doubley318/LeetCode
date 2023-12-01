#include "mylib.h"

class MinStack
{
public:
    /** initialize your data structure here. */
    stack<int> minarray;
    stack<int> sta;
    MinStack()
    {
    }

    void push(int x)
    {
        sta.push(x);
        if (minarray.empty())
            minarray.push(x);
        else
        {
            if (x < minarray.top())
                minarray.push(x);
            else
                minarray.push(minarray.top());
        }
    }

    void pop()
    {
        sta.pop();
        minarray.pop();
    }

    int top()
    {
        return sta.top();
    }

    int min()
    {
        return minarray.top();
    }
};

int main()
{
    return 0;
}