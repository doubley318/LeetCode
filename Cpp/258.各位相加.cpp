/*
 * @lc app=leetcode.cn id=258 lang=cpp
 *
 * [258] 各位相加
 */

// @lc code=start
class Solution
{
public:
    int addDigits(int num)
    {
        while (num >= 10)
        {
            string s = to_string(num);
            num = 0;
            for (int i = 0; i < s.size(); i++)
                num += s[i] - '0';
        }
        return num;
    }
};
// @lc code=end
