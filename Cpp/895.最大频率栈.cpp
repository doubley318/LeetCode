/*
 * @lc app=leetcode.cn id=895 lang=cpp
 *
 * [895] 最大频率栈
 */

// @lc code=start
class FreqStack
{
public:
    unordered_map<int, int> freq;
    unordered_map<int, stack<int>> frestack;
    int max_freq;
    FreqStack()
    {
        max_freq = 0;
    }

    void push(int val)
    {
        freq[val]++;
        max_freq = max(max_freq, freq[val]);
        frestack[freq[val]].push(val);
    }

    int pop()
    {
        int ret = frestack[max_freq].top();
        frestack[max_freq].pop();
        freq[ret]--;
        if (frestack[max_freq].empty())
        {
            max_freq--;
        }
        return ret;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
// @lc code=end
