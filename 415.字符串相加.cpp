/*
 * @lc app=leetcode.cn id=415 lang=cpp
 *
 * [415] 字符串相加
 */

// @lc code=start
class Solution
{
public:
    string addStrings(string num1, string num2)
    {
        string res = "";
        int point1 = num1.length() - 1, point2 = num2.length() - 1;
        int mark = 0, tmp;
        while (point1 >= 0 && point2 >= 0)
        {
            tmp = mark + (num1[point1] - '0') + (num2[point2] - '0');
            mark = tmp / 10;
            res = to_string(tmp % 10) + res;
            --point1;
            --point2;
        }
        while (point1 >= 0)
        {
            tmp = mark + (num1[point1] - '0');
            mark = tmp / 10;
            res = to_string(tmp % 10) + res;
            --point1;
        }
        while (point2 >= 0)
        {
            tmp = mark + (num2[point2] - '0');
            mark = tmp / 10;
            res = to_string(tmp % 10) + res;
            --point2;
        }
        if (mark == 1)
            res = to_string(1) + res;
        return res;
    }
};
// @lc code=end
