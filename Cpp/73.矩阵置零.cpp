/*
 * @lc app=leetcode.cn id=73 lang=cpp
 *
 * [73] 矩阵置零
 */

// @lc code=start
class Solution
{
public:
    /*
    Your runtime beats 33.94 % of cpp submissions
    Your memory usage beats 12.27 % of cpp submissions (13.1 MB)
        void setZeroes(vector<vector<int>>& matrix) {
            set<int> row;
            set<int> col;
            for (int i = 0; i < matrix.size(); i++)
            {
                for (int j = 0; j < matrix[0].size(); j++)
                {
                    if (matrix[i][j] == 0)
                    {
                        row.insert(i);
                        col.insert(j);
                    }
                }
            }
            for (auto i : row)
                for (int j = 0; j < matrix[0].size(); j++)
                    matrix[i][j] = 0;
            for (auto i : col)
                for (int j = 0; j < matrix.size(); j++)
                    matrix[j][i] = 0;
        }
    */

   //Your runtime beats 96.25 % of cpp submissions
   //Your memory usage beats 45.81 % of cpp submissions (12.9 MB)
    void setZeroes(vector<vector<int>> &matrix)
    {
        int row = 0, col = 0;
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                if (matrix[i][j] == 0)
                {
                    if (i == 0)
                        row = 1;
                    if (j == 0)
                        col = 1;
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for (int i = 1; i < matrix.size(); i++)
            if (matrix[i][0] == 0)
                for (int j = 1; j < matrix[0].size(); j++)
                    matrix[i][j] = 0;
        for (int i = 1; i < matrix[0].size(); i++)
            if (matrix[0][i] == 0)
                for (int j = 1; j < matrix.size(); j++)
                    matrix[j][i] = 0;
        if (row == 1)
            for (int i = 0; i < matrix[0].size(); i++)
                matrix[0][i] = 0;
        if (col == 1)
            for (int i = 0; i < matrix.size(); i++)
                matrix[i][0] = 0;
    }
};
// @lc code=end
