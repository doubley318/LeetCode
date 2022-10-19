/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
class Solution
{
public:
    void bfs(vector<vector<char>> &grid, int l, int n)
    {
        if (l < 0 || n < 0 || l >= grid.size() || n >= grid[0].size() || grid[l][n] != '1')
            return;
        grid[l][n] = '2';
        bfs(grid, l - 1, n);
        bfs(grid, l + 1, n);
        bfs(grid, l, n - 1);
        bfs(grid, l, n + 1);
    }

    int numIslands(vector<vector<char>> &grid)
    {
        int ans = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == '1')
                {
                    ans++;
                    bfs(grid, i, j);
                }
            }
        }
        return ans;
    }
};
// @lc code=end
