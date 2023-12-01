/*
 * @lc app=leetcode.cn id=1277 lang=cpp
 *
 * [1277] 统计全为 1 的正方形子矩阵
 */

// @lc code=start
class Solution
{
public:
    int countSquares(vector<vector<int>> &matrix)
    {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<int> myMatrix(col, 0);
        int pre = 0, tmp = 0, res = 0;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (matrix[i][j] == 1)
                {
                    if (i == 0 || j == 0)
                    {
                        pre = myMatrix[j];
                        myMatrix[j] = 1;
                    }
                    else
                    {
                        tmp = myMatrix[j];
                        myMatrix[j] = min(myMatrix[j - 1], min(myMatrix[j], pre)) + 1;
                        pre = tmp;
                    }
                    res += myMatrix[j];
                }
                else
                {
                    pre = myMatrix[j];
                    myMatrix[j] = 0;
                }
            }
        }
        return res;
    }
};
// @lc code=end
