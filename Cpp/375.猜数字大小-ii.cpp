/*
 * @lc app=leetcode.cn id=375 lang=cpp
 *
 * [375] 猜数字大小 II
 */

// @lc code=start
class Solution
{
public:
    int getMoneyAmount(int n)
    {
        vector<vector<int>> dp(n + 2, vector<int>(n + 2));
        for (int i = n - 1; i >= 1; i--)
        {
            for (int j = i + 1; j <= n; j++)
            {
                int tmp = INT_MAX;
                for (int k = i; k < j; k++)
                {
                    tmp = min(tmp, max(dp[i][k - 1], dp[k + 1][j]) + k);
                }
                dp[i][j] = tmp;
            }
        }
        return dp[1][n];
    }
};
// @lc code=end
