/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */

// @lc code=start
class Solution
{
public:
    int numSquares(int n)
    {
        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            int tmp = INT_MAX;
            for (int j = 1; j * j <= i; j++)
            {
                tmp = min(tmp, dp[i - j * j]);
            }
            dp[i] = tmp + 1;
        }
        return dp[n];
    }
};
// @lc code=end
