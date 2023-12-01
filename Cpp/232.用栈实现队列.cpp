/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */

// @lc code=start
class MyQueue {
public:
    stack<int> sta1;
    stack<int> sta2;
    int which = 1;
    int front = 0;
    MyQueue()
    {
    }

    void push(int x)
    {
        if (front == 0)
            front = x;
        if (which == 1)
            sta1.push(x);
        else
        {
            while (!sta2.empty())
            {
                sta1.push(sta2.top());
                sta2.pop();
            }
            sta1.push(x);
            which = 1;
        }
    }

    int pop()
    {
        if (which == 1)
        {
            while (sta1.size() > 1)
            {
                sta2.push(sta1.top());
                sta1.pop();
            }
            front = sta2.empty() ? 0 : sta2.top();
            int ans = sta1.top();
            sta1.pop();
            which = 2;
            return ans;
        }
        else
        {
            int ans = sta2.top();
            sta2.pop();
            front = sta2.empty() ? 0 : sta2.top();
            return ans;
        }
    }

    int peek()
    {
        return front;
    }

    bool empty()
    {
        if (which == 1)
            return sta1.empty();
        return sta2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end

