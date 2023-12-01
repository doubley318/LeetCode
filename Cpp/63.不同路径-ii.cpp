/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 */

// @lc code=start
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.size() == 1)
        {
            for (int i = 0; i < obstacleGrid[0].size(); i++)
            {
                if (obstacleGrid[0][i] == 1)
                    return 0;
            }
            return 1;
        }
        if (obstacleGrid[0].size() == 1)
        {
            for (int i = 0; i < obstacleGrid.size(); i++)
            {
                if (obstacleGrid[i][0] == 1)
                    return 0;
            }
            return 1;
        }
        vector<int> dp(obstacleGrid[0].size() + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < obstacleGrid.size(); i++)
        {
            for (int j = 0; j < obstacleGrid[i].size(); j++)
            {
                if (obstacleGrid[i][j] != 1)
                    dp[j + 1] = dp[j + 1] + dp[j];
                else
                    dp[j + 1] = 0;
            }
            dp[0] = 0;
        }
        return dp[obstacleGrid[0].size()];
    }
};
// @lc code=end

