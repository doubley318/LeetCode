/*
 * @lc app=leetcode.cn id=931 lang=cpp
 *
 * [931] 下降路径最小和
 */

// @lc code=start
class Solution {
public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                matrix[i][j] += min(j - 1 < 0 ? 100000 : matrix[i - 1][j - 1], min(matrix[i - 1][j], j + 1 < n ? matrix[i - 1][j + 1] : 100000));
            }
        }
        int res = 100000;
        for (int i = 0; i < n; i++)
        {
            res = min(res, matrix[n - 1][i]);
        }
        return res;
    }
};
// @lc code=end

