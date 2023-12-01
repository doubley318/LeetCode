/*
 * @lc app=leetcode.cn id=1599 lang=cpp
 *
 * [1599] 经营摩天轮的最大利润
 */

// @lc code=start
class Solution
{
public:
    int minOperationsMaxProfit(vector<int> &customers, int boardingCost, int runningCost)
    {
        int income = 0, res = -1;
        int n = customers.size();
        int server = 0, lost = 0;
        for (int i = 0; i < n; i++)
        {
            lost += customers[i];
            if (lost < 4)
            {
                server += lost;
                lost = 0;
            }
            else
            {
                server += 4;
                lost -= 4;
            }
            int tmp = server * boardingCost - runningCost * (i + 1);
            if (tmp > income)
            {
                income = tmp;
                res = i + 1;
            }
        }
        while (lost)
        {
            n = n + 1;
            if (lost < 4)
            {
                server += lost;
                lost = 0;
            }
            else
            {
                lost -= 4;
                server += 4;
            }
            int tmp = server * boardingCost - runningCost * n;
            if (tmp > income)
            {
                income = tmp;
                res = n;
            }
        }
        return res;
    }
};
// @lc code=end
