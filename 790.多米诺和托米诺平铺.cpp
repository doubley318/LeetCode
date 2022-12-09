/*
 * @lc app=leetcode.cn id=790 lang=cpp
 *
 * [790] 多米诺和托米诺平铺
 */

// @lc code=start
class Solution
{
public:
    int numTilings(int n)
    {
        vector<long long> dp(n + 1, 0);
        dp[1] = 1;
        if (n >= 2)
            dp[2] = 2;
        if (n >= 3)
            dp[3] = 5;
        for (int i = 4; i <= n; i++)
        {
            dp[i] = (2 * dp[i - 1] + dp[i - 3]) % 1000000007;
        }
        return dp[n];
    }
};
// @lc code=end
