/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数
 */

// @lc code=start
class Solution
{
public:
    int fib(int n)
    {
        if (n == 0)
            return 0;
        int pre = 0;
        int mid = 1;
        int ret = 1;
        for (int i = 2; i <= n; i++)
        {
            ret = mid + pre;
            pre = mid;
            mid = ret;
        }
        return ret;
    }
};
// @lc code=end
