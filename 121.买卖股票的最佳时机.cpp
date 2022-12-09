/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int ret = 0;
        int tmp = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            tmp += prices[i] - prices[i - 1];
            if (tmp < 0)
                tmp = 0;
            ret = max(tmp, ret);
        }
        return ret;
    }
};
// @lc code=end
