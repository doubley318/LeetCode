/*
 * @lc app=leetcode.cn id=901 lang=cpp
 *
 * [901] 股票价格跨度
 */

// @lc code=start
class StockSpanner
{
public:
    stack<pair<int, int>> sta;
    StockSpanner()
    {
        sta.emplace();
    }

    int next(int price)
    {
        if (sta.empty() || sta.top().first > price)
        {
            sta.push({price, 1});
            return 1;
        }
        else
        {
            int tmp = 0;
            while (!sta.empty() && sta.top().first <= price)
            {
                tmp += sta.top().second;
                sta.pop();
            }
            sta.push({price, tmp + 1});
            return tmp + 1;
        }
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
// @lc code=end
