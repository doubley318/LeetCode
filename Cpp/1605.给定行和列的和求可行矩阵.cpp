/*
 * @lc app=leetcode.cn id=1605 lang=cpp
 *
 * [1605] 给定行和列的和求可行矩阵
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> restoreMatrix(vector<int> &rowSum, vector<int> &colSum)
    {
        int row = rowSum.size(), col = colSum.size();
        vector<vector<int>> res(row, vector<int>(col, 0));
        int i = 0, j = 0;
        while (i < row && j < col)
        {
            res[i][j] = min(rowSum[i], colSum[j]);
            rowSum[i] -= res[i][j];
            colSum[j] -= res[i][j];
            if (rowSum[i] == 0)
                i++;
            if (colSum[j] == 0)
                j++;
        }
        return res;
    }
};
// @lc code=end
