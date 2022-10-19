/*
 * @lc app=leetcode.cn id=902 lang=cpp
 *
 * [902] 最大为 N 的数字组合
 */

// @lc code=start
class Solution
{
public:
    int atMostNGivenDigitSet(vector<string> &digits, int n)
    {
        vector<int> x(digits.size(), 0);
        for (int i = 0; i < x.size(); i++)
            x[i] = stoi(digits[i]);
        int i = 1;
        int ret = 0;
        while (pow(10, i) <= n)
        {
            ret = ret + pow(digits.size(), i);
            i = i + 1;
        }
        i = i - 1;
        int tmp = 0;
        string s = to_string(n);
        i = 0;
        int m = 0;
        for (; i < s.size(); i++)
        {
            if (s[i] - '0' < x[0])
                break;
            int mark = 0;
            m = 0;
            for (; m < x.size(); m++)
            {
                if (s[i] - '0' > x[m])
                    mark++;
                else
                    break;
            }
            tmp = tmp + mark * pow(x.size(), s.size() - i - 1);
        }
        if (i == s.size())
            i--;
        if (s[i] - '0' == x[m] || s[i] - '0' == x[0])
            tmp++;
        return ret + tmp;
    }
};
// @lc code=end
