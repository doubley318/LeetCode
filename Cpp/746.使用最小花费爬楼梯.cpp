/*
 * @lc app=leetcode.cn id=746 lang=cpp
 *
 * [746] 使用最小花费爬楼梯
 */

// @lc code=start
class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int pre = 0;
        int mid = cost[0];
        int ret = 0;
        for (int i = 1; i < cost.size(); i++)
        {
            ret = min(pre + cost[i], mid + cost[i]);
            pre = mid;
            mid = ret;
        }
        return min(pre, mid);
    }
};
// @lc code=end
