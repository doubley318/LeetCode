#include "mylib.h"

class Solution
{
public:
    int maxValue(vector<vector<int>> &grid)
    {
        int row = grid.size(), col = grid[0].size();
        for (int i = 1; i < col; i++)
        {
            grid[0][i] = grid[0][i - 1] + grid[0][i];
        }
        for (int i = 1; i < row; i++)
        {
            grid[i][0] = grid[i][0] + grid[i - 1][0];
        }
        for (int i = 1; i < row; i++)
        {
            for (int j = 1; j < col; j++)
            {
                grid[i][j] = max(grid[i - 1][j], grid[i][j - 1]) + grid[i][j];
            }
        }
        return grid[row - 1][col - 1];
    }
};

int main()
{
    return 0;
}