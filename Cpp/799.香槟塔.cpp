/*
 * @lc app=leetcode.cn id=799 lang=cpp
 *
 * [799] 香槟塔
 */

// @lc code=start
class Solution
{
public:
    double champagneTower(int poured, int query_row, int query_glass)
    {
        vector<vector<double>> beizi(query_row + 1, vector<double>(query_row + 2));
        beizi[0][0] = poured;
        for (int i = 0; i < query_row; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                if (beizi[i][j] <= 1)
                    continue;
                beizi[i + 1][j] += (beizi[i][j] - 1) / 2;
                beizi[i + 1][j + 1] += (beizi[i][j] - 1) / 2;
            }
        }
        return beizi[query_row][query_glass] > 1 ? 1 : beizi[query_row][query_glass];
    }
};
// @lc code=end
