/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
class Solution
{
public:
    int climbStairs(int n)
    {
        int pre = 0;
        int mid = 1;
        int ret = 1;
        for (int i = 1; i <= n; i++)
        {
            ret = mid + pre;
            pre = mid;
            mid = ret;
        }
        return ret;
    }
};
// @lc code=end
