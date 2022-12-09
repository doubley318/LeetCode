/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
class Solution
{
public:
    void bfs(vector<vector<char>> &image, int sr, int sc)
    {
        if (sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size() || image[sr][sc] != '1')
            return;
        image[sr][sc] = '2';
        bfs(image, sr - 1, sc);
        bfs(image, sr, sc - 1);
        bfs(image, sr, sc + 1);
        bfs(image, sr + 1, sc);
    }

    int numIslands(vector<vector<char>> &grid)
    {
        int ret = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == '1')
                {
                    bfs(grid, i, j);
                    ret++;
                }
            }
        }
        return ret;
    }
};
// @lc code=end
