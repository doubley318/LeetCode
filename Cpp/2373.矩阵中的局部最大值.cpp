/*
 * @lc app=leetcode.cn id=2373 lang=cpp
 *
 * [2373] 矩阵中的局部最大值
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> largestLocal(vector<vector<int>> &grid)
    {
        int row = grid.size(), col = grid[0].size();
        vector<vector<int>> res(row - 2, vector<int>(col - 2, 0));
        for (int i = 0; i < row - 2; i++)
        {
            for (int j = 0; j < col - 2; j++)
            {
                int tmp = 0;
                for (int x = i; x < i + 3; x++)
                {
                    for (int y = j; y < j + 3; y++)
                    {
                        tmp = max(tmp, grid[x][y]);
                    }
                }
                res[i][j] = tmp;
            }
        }
        return res;
    }
};
// @lc code=end
