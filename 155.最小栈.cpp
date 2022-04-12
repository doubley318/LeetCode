/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */

// @lc code=start
class MinStack {
stack<pair<int, int>> msta;

public:
    MinStack()
    {
    }

    void push(int val)
    {
        if (msta.size() == 0)
            msta.push(pair<int, int>(val, val));
        else
            msta.push(pair<int, int>(val, min(msta.top().second, val)));
    }

    void pop()
    {
        msta.pop();
    }

    int top()
    {
        return msta.top().first;
    }

    int getMin()
    {
        return msta.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

