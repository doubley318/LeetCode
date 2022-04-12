/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 */

// @lc code=start
class MyStack {queue<int> zhengxiaolu;
    queue<int> renshuangyin;
    int tmp = 0;

public:
    MyStack()
    {
    }

    void push(int x)
    {
        if (tmp == 0)
            zhengxiaolu.push(x);
        else
            renshuangyin.push(x);
    }

    int pop()
    {
        if (tmp == 0)
        {
            tmp = 1;
            while (zhengxiaolu.size() - 1)
            {
                renshuangyin.push(zhengxiaolu.front());
                zhengxiaolu.pop();
            }
            int i = zhengxiaolu.front();
            zhengxiaolu.pop();
            return i;
        }
        else
        {
            tmp = 0;
            while (renshuangyin.size() - 1)
            {
                zhengxiaolu.push(renshuangyin.front());
                renshuangyin.pop();
            }
            int i = renshuangyin.front();
            renshuangyin.pop();
            return i;
        }
    }

    int top()
    {
        if (tmp == 0)
        {
            tmp = 1;
            while (zhengxiaolu.size() - 1)
            {
                renshuangyin.push(zhengxiaolu.front());
                zhengxiaolu.pop();
            }
            renshuangyin.push(zhengxiaolu.front());
            int i = zhengxiaolu.front();
            zhengxiaolu.pop();
            return i;
        }
        else
        {
            tmp = 0;
            while (renshuangyin.size() - 1)
            {
                zhengxiaolu.push(renshuangyin.front());
                renshuangyin.pop();
            }
            zhengxiaolu.push(renshuangyin.front());
            int i = renshuangyin.front();
            renshuangyin.pop();
            return i;
        }
    }

    bool empty()
    {
        if (tmp == 0)
            return zhengxiaolu.size() == 0;
        else
            return renshuangyin.size() == 0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end

