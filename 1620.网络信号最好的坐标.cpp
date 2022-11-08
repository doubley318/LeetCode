/*
 * @lc app=leetcode.cn id=1620 lang=cpp
 *
 * [1620] 网络信号最好的坐标
 */

// @lc code=start
class Solution
{
    int r;

public:
    int distant(int ax, int ay, int bx, int by, int q)
    {
        double d = sqrt((ax - bx) * (ax - bx) + (ay - by) * (ay - by));
        if (d > r)
            return 0;
        return q / (1 + d);
    }
    vector<int> bestCoordinate(vector<vector<int>> &towers, int radius)
    {
        r = radius;
        int min_x = 51, min_y = 51, max_x = 0, max_y = 0;
        for (auto t : towers)
        {
            min_x = min_x > t[0] ? t[0] : min_x;
            min_y = min_y > t[1] ? t[1] : min_y;
            max_x = max_x < t[0] ? t[0] : max_x;
            max_y = max_y < t[1] ? t[1] : max_y;
        }
        vector<vector<int>> M(51, vector<int>(51, 0));
        for (int k = 0; k < towers.size(); k++)
        {
            for (int i = min_x; i < max_x + 1; i++)
            {
                for (int j = min_y; j < max_y + 1; j++)
                {
                    M[i][j] += distant(i, j, towers[k][0], towers[k][1], towers[k][2]);
                }
            }
        }
        vector<int> ret = {0, 0};
        int m = 0;
        for (int i = min_x; i < max_x + 1; i++)
        {
            for (int j = min_y; j < max_y + 1; j++)
            {
                if (m < M[i][j])
                {
                    m = M[i][j];
                    ret = {i, j};
                }
            }
        }
        return ret;
    }
};
// @lc code=end
