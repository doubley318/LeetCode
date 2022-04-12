/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int row = matrix.size() - 1, col = 0;
        while (row >= 0 && col < matrix[0].size())
        {
            if (matrix[row][col] == target)
                return true;
            else if (matrix[row][col] > target)
                row--;
            else
                col++;
        }
        return false;
    }
};
// @lc code=end

