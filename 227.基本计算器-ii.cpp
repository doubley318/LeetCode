/*
 * @lc app=leetcode.cn id=227 lang=cpp
 *
 * [227] 基本计算器 II
 */

// @lc code=start
class Solution
{
public:
    long long result(char c, int a, int b)
    {
        long long ret = 0;
        switch (c)
        {
        case '+':
            ret = a + b;
            break;
        case '-':
            ret = b - a;
            break;
        case '*':
            ret = a * b;
            break;
        case '/':
            ret = b / a;
            break;
        }
        return ret;
    }
    int calculate(string s)
    {
        stack<long long> nums;
        // +:1, -:-1, *:2, /:-2
        unordered_map<char, int> samop = {{'+', 1}, {'-', -1}, {'*', 2}, {'/', -2}};
        stack<char> ops;
        long long tmp = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] <= '9' && s[i] >= '0')
            {
                tmp = tmp * 10 + s[i] - '0';
            }
            else if (s[i] != ' ')
            {
                nums.push(tmp);
                tmp = 0;
                while (!ops.empty() && abs(samop[ops.top()]) >= abs(samop[s[i]]))
                {
                    long long a = nums.top();
                    nums.pop();
                    long long b = nums.top();
                    nums.pop();
                    nums.push(result(ops.top(), a, b));
                    ops.pop();
                }
                ops.push(s[i]);
            }
        }
        nums.push(tmp);
        long long a, b;
        while (!ops.empty())
        {
            a = nums.top();
            nums.pop();
            b = nums.top();
            nums.pop();
            nums.push(result(ops.top(), a, b));
            ops.pop();
        }
        return nums.top();
    }
};
// @lc code=end
