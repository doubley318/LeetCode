/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<vector<int>> &matrix)
    {
        for (int i = 0; i < (matrix.size() + 1) / 2; i++)
            ro(matrix, i);
    }

    void ro(vector<vector<int>> &matrix, int n)
    {
        int ms = matrix.size();
        for (int i = n; i < ms - 1 - n; i++)
        {
            int tmp = matrix[n][i];
            matrix[n][i] = matrix[ms - 1 - i][n];
            matrix[ms - 1 - i][n] = matrix[ms - n - 1][ms - i - 1];
            matrix[ms - n - 1][ms - i - 1] = matrix[i][ms - 1 - n];
            matrix[i][ms - 1 - n] = tmp;
        }
    }
};
// @lc code=end

