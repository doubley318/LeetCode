/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原 IP 地址
 */

// @lc code=start
class Solution
{
public:
    vector<string> ans;
    vector<string> restoreIpAddresses(string s)
    {
        string a;
        int t = 0, l = 1, num = -1;
        small(s, t, a, l, num);
        return ans;
    }

    void small(string s, int t, string a, int l, int num)
    {
        if (l == 4 && t == s.length())
        {
            a = a + to_string(num);
            ans.push_back(a);
            return;
        }
        if (num == 0 && s[t] - '0' == 0)
            return;
        if (num == -1)
            num = 0;
        int tmp = s[t] - '0' + num * 10;
        if (l == 4)
        {
            small(s, t + 1, a, l, tmp);
            if (tmp > 255)
                return;
        }
        else
        {
            if (tmp > 255)
            {
                a = a + to_string(num) + ".";
                small(s, t, a, l + 1, -1);
            }
            else
                small(s, t + 1, a, l, tmp);
        }
    }
};
// @lc code=end
