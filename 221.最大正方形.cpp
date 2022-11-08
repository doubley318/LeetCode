/*
 * @lc app=leetcode.cn id=221 lang=cpp
 *
 * [221] 最大正方形
 */

// @lc code=start
class Solution
{
public:
    int maximalSquare(vector<vector<char>> &matrix)
    {
        vector<vector<int>> dp(matrix[0].size() + 1, vector<int>(2, 0));
        int ret = 0;
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                dp[j + 1][i % 2] = matrix[i][j] == '0' ? 0 : min(min(dp[j + 1][(i + 1) % 2], dp[j][(i + 1) % 2]), dp[j][i % 2]) + 1;
                ret = max(dp[j + 1][i % 2], ret);
            }
        }
        return ret * ret;
    }
};
// @lc code=end
