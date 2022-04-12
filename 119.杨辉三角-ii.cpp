/*
 * @lc app=leetcode.cn id=119 lang=cpp
 *
 * [119] 杨辉三角 II
 */

// @lc code=start
class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        vector<int> res(rowIndex + 1);
        res[0] = 1;
        for (int i = 1; i <= rowIndex; i++)
        {
            res[i] = 1;
            int tmp1 = res[0];
            int tmp2 = res[1];
            for (int j = 1; j < i; j++)
            {
                res[j] = tmp1 + tmp2;
                tmp1 = tmp2;
                tmp2 = res[j + 1];
            }
        }
        return res;
    }
};
// @lc code=end
