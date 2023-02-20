/*
 * @lc app=leetcode.cn id=813 lang=cpp
 *
 * [813] 最大平均值和的分组
 */

// @lc code=start
class Solution
{
public:
    double largestSumOfAverages(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> sum(n, 0);
        sum[0] = nums[0];
        for (int i = 1; i < n; i++)
        {
            sum[i] = sum[i - 1] + nums[i];
        }
        vector<vector<double>> dp(n, vector<double>(k + 1, 0));
        for (int i = 0; i < n; i++)
        {
            dp[i][1] = 1.0 * sum[i] / (i + 1);
        }
        for (int j = 2; j <= k; j++)
        {
            for (int i = j - 1; i < n; i++)
            {
                for (int l = i - 1; l >= j - 2; l--)
                {
                    dp[i][j] = max(dp[l][j - 1] + 1.0 * (sum[i] - sum[l]) / (i - l), dp[i][j]);
                }
            }
        }
        return dp[n - 1][k];
    }
};
// @lc code=end
