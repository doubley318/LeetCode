/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II
 */

// @lc code=start
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int i = matrix.size() - 1;
        int j = 0;
        while (i >= 0 && j < matrix[0].size())
        {
            if (target == matrix[i][j])
                return true;
            else if (target > matrix[i][j])
                j++;
            else
                i--;
        }
        return false;
    }
};
// @lc code=end
