/*
 * @lc app=leetcode.cn id=1796 lang=cpp
 *
 * [1796] 字符串中第二大的数字
 */

// @lc code=start
class Solution
{
public:
    int secondHighest(string s)
    {
        int ret = -1;
        int pre = -1;
        for (char i : s)
        {
            if (i >= '0' && i <= '9')
            {
                int tmp = i - '0';
                if (pre < tmp)
                {
                    ret = pre;
                    pre = tmp;
                }
                else if (pre != tmp && ret < tmp)
                {
                    ret = tmp;
                }
            }
        }
        return ret;
    }
};
// @lc code=end
