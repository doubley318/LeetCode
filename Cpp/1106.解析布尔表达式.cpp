/*
 * @lc app=leetcode.cn id=1106 lang=cpp
 *
 * [1106] 解析布尔表达式
 */

// @lc code=start
class Solution
{
public:
    bool parseBoolExpr(string expression)
    {
        // 算符栈
        stack<char> opertion;
        // 计算栈
        stack<int> s;
        for (int i = 0; i < expression.size(); i++)
        {
            // 左括号标记为-1作为计算的分割线
            if (expression[i] == '(')
            {
                s.push(-1);
            }
            else if (expression[i] == 'f' || expression[i] == 't')
            {
                s.push(expression[i] == 'f' ? 0 : 1);
            }
            else if (expression[i] == '!' || expression[i] == '&' || expression[i] == '|')
            {
                opertion.push(expression[i]);
            }
            else if (expression[i] == ')')
            {
                if (!opertion.empty())
                {
                    char op = opertion.top();
                    opertion.pop();
                    if (!s.empty())
                    {
                        int temp = s.top();
                        s.pop();
                        if (op == '!')
                        {
                            temp = abs(temp - 1);
                        }
                        else if (op == '&')
                        {
                            while (!s.empty() && s.top() != -1)
                            {
                                temp *= s.top();
                                s.pop();
                            }
                        }
                        else
                        {
                            while (!s.empty() && s.top() != -1)
                            {
                                temp |= s.top();
                                s.pop();
                            }
                        }
                        s.pop();
                        s.push(temp);
                    }
                }
            }
        }
        return s.top();
    }
};
// @lc code=end
