/*
 * @lc app=leetcode.cn id=1247 lang=cpp
 *
 * [1247] 交换字符使得字符串相同
 */

// @lc code=start
class Solution
{
public:
    int minimumSwap(string s1, string s2)
    {
        int diff_x = 0, diff_y = 0;
        int n = s1.size();
        for (int i = 0; i < n; i++)
        {
            if (s1[i] != s2[i])
            {
                if (s1[i] == 'x')
                    diff_x++;
                else
                    diff_y++;
            }
        }
        if ((diff_x + diff_y) % 2)
            return -1;
        int ret = 0;
        if (diff_x % 2 == 1)
            ret += diff_x / 2 + 2;
        else
            ret += diff_x / 2;
        return ret + diff_y / 2;
    }
};
// @lc code=end
