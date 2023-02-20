/*
 * @lc app=leetcode.cn id=1945 lang=cpp
 *
 * [1945] 字符串转化后的各位数字之和
 */

// @lc code=start
class Solution
{
public:
    int getLucky(string s, int k)
    {
        string tmp;
        int n = s.size();
        for (int i = 0; i < n; i++)
            tmp += to_string(s[i] - 'a' + 1);
        int ret = 0;
        for (int i = 0; i < tmp.size(); i++)
            ret += tmp[i] - '0';
        while (k > 1)
        {
            int t = ret;
            ret = 0;
            while (t > 0)
            {
                ret += t % 10;
                t /= 10;
            }
            k--;
        }
        return ret;
    }
};
// @lc code=end
