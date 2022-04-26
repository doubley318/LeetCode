#include "mylib.h"

class Solution
{
public:
    int projectionArea(vector<vector<int>> &grid)
    {
        int down = 0, left = 0, front = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            int left_num = 0, front_num = 0;
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] != 0)
                    down++;
                left_num = max(left_num, grid[i][j]);
                front_num = max(front_num, grid[j][i]);
            }
            left += left_num;
            front += front_num;
        }
        return down + left + front;
    }
};

int main()
{

    return 0;
}