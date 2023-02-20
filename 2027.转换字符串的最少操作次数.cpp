/*
 * @lc app=leetcode.cn id=2027 lang=cpp
 *
 * [2027] 转换字符串的最少操作次数
 */

// @lc code=start
class Solution
{
public:
    int minimumMoves(string s)
    {
        int ret = 0, n = s.size();
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'X')
            {
                ret++;
                i += 2;
            }
        }
        return ret;
    }
};
// @lc code=end
