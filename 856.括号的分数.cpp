/*
 * @lc app=leetcode.cn id=856 lang=cpp
 *
 * [856] 括号的分数
 */

// @lc code=start
class Solution
{
public:
    int scoreOfParentheses(string s)
    {
        stack<int> sta;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
                sta.push(0);
            else
            {
                if (sta.top() == 0)
                {
                    sta.pop();
                    int tmp = 1;
                    if (!sta.empty())
                    {
                        tmp = sta.top();
                        if (tmp != 0)
                        {
                            tmp = tmp + 1;
                            sta.pop();
                        }
                        tmp = tmp == 0 ? 1 : tmp;
                    }
                    sta.push(tmp);
                }
                else
                {
                    int tmp = sta.top();
                    tmp = tmp * 2;
                    sta.pop();
                    sta.pop();
                    if (!sta.empty() && sta.top() != 0)
                    {
                        tmp = tmp + sta.top();
                        sta.pop();
                    }
                    sta.push(tmp);
                }
            }
        }
        return sta.top();
    }
};
// @lc code=end
