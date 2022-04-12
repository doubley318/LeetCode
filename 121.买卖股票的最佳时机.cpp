/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int tmp = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            int t = prices[i] - prices[i - 1];
            tmp = tmp + t > 0 ? tmp + t : 0;
            res = max(tmp, res);
        }
        return res;
    }
};
// @lc code=end

