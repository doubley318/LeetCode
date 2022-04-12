/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */
//直接pow
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 5.1 % of cpp submissions (6.1 MB)
//自己二分pow
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 25.08 % of cpp submissions (5.9 MB)
// @lc code=start
class Solution
{
public:
    double myPow(double x, int n)
    {
        if (n == 0)
            return (double)1.0;
        double sign = 1;
        if (n < 0)
            sign = -1;
        double res;
        res = smallpow(x, (double)n * sign);
        return sign == 1 ? res : (double)(1 / res);
    }

    double smallpow(double x, double n)
    {
        if (n == 1)
            return x;
        if (n == 0)
            return 1;
        double res = x;
        double N = 2;
        while (N <= n)
        {
            res = res * res;
            N = N * 2;
        }
        res = res * smallpow(x, n - N / 2);
        return res;
    }
};
// @lc code=end
