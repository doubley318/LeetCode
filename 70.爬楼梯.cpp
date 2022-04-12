/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
class Solution {
public:
    int climbStairs(int n)
    {
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;
        int dp;
        int dp0 = 1;
        int dp1 = 2;
        for (int i = 2; i < n; i++)
        {
            dp = dp1 + dp0;
            dp0 = dp1;
            dp1 = dp;
        }
        return dp;
    }
};
// @lc code=end

