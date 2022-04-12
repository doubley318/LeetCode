/*
 * @lc app=leetcode.cn id=8 lang=cpp
int main()
{
    Solution so;
    string s = "   -g-  4193   with words";
    cout << so.myAtoi(s) << endl;
    return 0;
}
 * [8] 字符串转换整数 (atoi)
 */
// Your runtime beats 66.97 % of cpp submissions
// Your memory usage beats 98.55 % of cpp submissions (6.7 MB)

// @lc code=start
class Solution
{
public:
    int myAtoi(string s)
    {
        long r = 0;
        int flag = 1;
        int step = 1;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ' ' && step == 1)
                continue;
            if (s[i] == '-')
            {
                if (step == 2)
                    return 0;
                if (step == 3)
                    return (int)r;
                flag = -1;
                step = 2;
            }
            else if (s[i] == '+')
            {
                if (step == 2)
                    return 0;
                if (step == 3)
                    return (int)r;
                flag = 1;
                step = 2;
            }
            else if (s[i] >= '0' && s[i] <= '9')
            {
                if (flag == -1)
                {
                    r = r * 10 - (s[i] - '0');
                    if (r < -2147483648)
                        return -2147483648;
                }
                else
                {
                    r = r * 10 + (s[i] - '0');
                    if (r > 2147483647)
                        return 2147483647;
                }
                step = 3;
            }
            else
                return (int)r;
        }
        return (int)r;
    }
};
// @lc code=end
