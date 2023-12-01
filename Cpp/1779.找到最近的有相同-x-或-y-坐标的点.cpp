/*
 * @lc app=leetcode.cn id=1779 lang=cpp
 *
 * [1779] 找到最近的有相同 X 或 Y 坐标的点
 */

// @lc code=start
class Solution
{
public:
    int nearestValidPoint(int x, int y, vector<vector<int>> &points)
    {
        int ans = INT_MAX;
        int ret = -1;
        for (int i = 0; i < points.size(); i++)
        {
            if (points[i][0] == x || points[i][1] == y)
            {
                int tmp = abs(points[i][0] - x) + abs(points[i][1] - y);
                if (tmp < ans)
                    ans = tmp, ret = i;
            }
        }
        return ret;
    }
};
// @lc code=end
