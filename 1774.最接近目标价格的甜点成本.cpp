/*
 * @lc app=leetcode.cn id=1774 lang=cpp
 *
 * [1774] 最接近目标价格的甜点成本
 */

// @lc code=start
class Solution
{
public:
    int closestCost(vector<int> &baseCosts, vector<int> &toppingCosts, int target)
    {
        int ret = INT_MAX;
        int x = *min_element(baseCosts.begin(), baseCosts.end());
        if (x >= target)
            return x;
        vector<bool> dp(target + 1, false);
        for (int i : baseCosts)
        {
            if (i <= target)
                dp[i] = true;
            else
                ret = min(ret, i);
        }
        for (int i : toppingCosts)
        {
            for (int j = 1; j <= 2; j++)
            {
                for (int k = target; k > 0; k--)
                {
                    if (dp[k] && i + k > target)
                        ret = min(ret, i + k);
                    if (k - i > 0)
                        dp[k] = dp[k] | dp[k - i];
                }
            }
        }
        for (int i = 0; i <= ret - target; ++i)
        {
            if (dp[target - i])
            {
                return target - i;
            }
        }
        return ret;
    }
};
// @lc code=end
