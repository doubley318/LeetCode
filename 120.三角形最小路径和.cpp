/*
 * @lc app=leetcode.cn id=120 lang=cpp
 *
 * [120] 三角形最小路径和
 */

// @lc code=start
class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int ans = triangle[0][0];
        for (int i = 1; i < triangle.size(); i++)
        {
            triangle[i][0] += triangle[i - 1][0];
            for (int j = 1; j < i; j++)
            {
                int a = triangle[i][j] + triangle[i - 1][j - 1];
                int b = triangle[i][j] + triangle[i - 1][j];
                triangle[i][j] = a < b ? a : b;
            }
            triangle[i][i] += triangle[i - 1][i - 1];
            if (i == triangle.size() - 1)
            {
                ans = triangle[i][0];
                for (int j = 1; j < i + 1; j++)
                    ans = ans < triangle[i][j] ? ans : triangle[i][j];
            }
        }
        return ans;
    }
};
// @lc code=end
