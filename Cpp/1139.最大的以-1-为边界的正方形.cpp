/*
 * @lc app=leetcode.cn id=1139 lang=cpp
 *
 * [1139] 最大的以 1 为边界的正方形
 */

// @lc code=start
class Solution
{
public:
    int largest1BorderedSquare(vector<vector<int>> &grid)
    {
        vector<vector<int>> tmp = grid;
        int row = grid.size(), col = grid[0].size();
        for (int i = 0; i < row; i++)
        {
            for (int j = 1; j < col; j++)
            {
                if (grid[i][j])
                    grid[i][j] += grid[i][j - 1];
            }
        }
        for (int i = 0; i < col; i++)
        {
            for (int j = 1; j < row; j++)
            {
                if (tmp[j][i])
                    tmp[j][i] += tmp[j - 1][i];
            }
        }
        int ret = 0;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                int t = min(grid[i][j], tmp[i][j]);
                while (t > 0 && (grid[i - t + 1][j] < t || tmp[i][j - t + 1] < t))
                    t--;
                ret = max(ret, t);
            }
        }
        return ret * ret;
    }
};
// @lc code=end
