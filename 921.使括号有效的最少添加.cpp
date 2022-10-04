/*
 * @lc app=leetcode.cn id=921 lang=cpp
 *
 * [921] 使括号有效的最少添加
 */

// @lc code=start
class Solution
{
public:
    int minAddToMakeValid(string s)
    {
        int l = 0, res = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (l == 0 && s[i] == ')')
                res++;
            else if (s[i] == '(')
                l++;
            else
                l--;
        }
        return res + l;
    }
};
// @lc code=end
