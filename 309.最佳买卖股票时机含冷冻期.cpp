/*
 * @lc app=leetcode.cn id=309 lang=cpp
 *
 * [309] 最佳买卖股票时机含冷冻期
 */

// @lc code=start
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        // 0 不持有
        // 1 持有
        vector<vector<int>> dp(prices.size() + 1, vector<int>(2, 0));
        dp[1][0] = 0,
        dp[1][1] = -prices[0];
        for (int i = 1; i < prices.size(); i++)
        {
            dp[i + 1][0] = max(dp[i][0], dp[i][1] + prices[i]);
            dp[i + 1][1] = max(dp[i][1], dp[i - 1][0] - prices[i]);
        }
        return max(dp[prices.size()][0], dp[prices.size()][1]);
    }
};
// @lc code=end
