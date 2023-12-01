/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 */

// @lc code=start
class Solution {
public:
    struct char_int
    {
        char c;
        int i;
    };

    int longestValidParentheses(string s)
    {
        if (s.size() == 0)
            return 0;
        stack<char_int> sta;
        char_int si;
        si.c = s[0];
        si.i = 0;
        sta.push(si);

        int i = 1;
        while (i < s.size())
        {
            if (!sta.empty() && s[i] == ')' && '(' == sta.top().c)
            {
                sta.pop();
                i++;
            }
            else
            {
                si.c = s[i];
                si.i = i;
                sta.push(si);
                i++;
            }
        }
        int max = 0;
        int tmp = s.size();
        while (!sta.empty())
        {
            int res = tmp - sta.top().i - 1;
            max = max > res ? max : res;
            tmp = sta.top().i;
            sta.pop();
        }
        max = max > tmp ? max : tmp;
        return max;
    }
};
// @lc code=end

