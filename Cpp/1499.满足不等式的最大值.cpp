/*
 * @lc app=leetcode.cn id=1499 lang=cpp
 *
 * [1499] 满足不等式的最大值
 */

// @lc code=start
class Solution
{
public:
    int findMaxValueOfEquation(vector<vector<int>> &points, int k)
    {
        // 等价于 xj+yj  +  yi-xi
        priority_queue<pair<int, int>> pq;
        int n = points.size();
        pq.push({points[0][1] - points[0][0], points[0][0]});
        int ret = INT_MIN;
        for (int i = 1; i < n; i++)
        {
            while (!pq.empty() && points[i][0] - pq.top().second > k)
            {
                pq.pop();
            }
            if (!pq.empty())
            {
                ret = max(ret, points[i][0] + points[i][1] + pq.top().first);
            }
            pq.push({points[i][1] - points[i][0], points[i][0]});
        }
        return ret;
    }
};
// @lc code=end
