/*
 * @lc app=leetcode.cn id=746 lang=cpp
 *
 * [746] 使用最小花费爬楼梯
 */

// @lc code=start
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost)
    {
        int tmp = 0, l = 0, r = 0;
        for (int i = 0; i < cost.size(); i++) {
            tmp = min(l + cost[i], r + cost[i]);
            l = r;
            r = tmp;
        }
        return min(l, r);
    }
};
// @lc code=end
