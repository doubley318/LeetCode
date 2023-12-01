/*
 * @lc app=leetcode.cn id=29 lang=cpp
 *
 * [29] 两数相除
 */

// @lc code=start
class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        int sign = 1;
        if ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0))
            sign = -1;
        dividend = dividend > 0 ? -dividend : dividend;
        divisor = divisor > 0 ? -divisor : divisor;
        int res = divnum(dividend, divisor);
        return sign == -1 ? res : -res;
    }

    int divnum(int a, int b)
    {
        if (a > b)
            return 0;
        int count = -1;
        int tmp = b;
        while (tmp >= -1073741824 && tmp + tmp >= a)
        {
            count += count;
            tmp += tmp;
        }
        return count + divnum(a - tmp, b);
    }
};
// @lc code=end
