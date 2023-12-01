#include "mylib.h"

class CQueue
{
public:
    stack<int> s1;
    stack<int> s2;
    bool state;
    CQueue()
    {
        state = true;
    }

    void appendTail(int value)
    {
        if (state)
            s1.push(value);
        else
        {
            state = true;
            while (!s2.empty())
            {
                s1.push(s2.top());
                s2.pop();
            }
            s1.push(value);
        }
    }

    int deleteHead()
    {
        if (state)
        {
            state = false;
            if (s1.empty())
                return -1;
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
            int ret = s2.top();
            s2.pop();
            return ret;
        }
        else
        {
            if (s2.empty())
                return -1;
            int ret = s2.top();
            s2.pop();
            return ret;
        }
    }
};

int main()
{
    CQueue *obj = new CQueue();
    obj->appendTail(3);
    cout << obj->deleteHead();
    cout << obj->deleteHead();
    cout << obj->deleteHead();
    return 0;
}