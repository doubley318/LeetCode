/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> res(m * n);
        int c = 0, r = 0, tmp = 0;
        for (int i = 0; i < m * n; i++)
        {
            res[i] = matrix[r][c];
            if (tmp % 4 == 0)
            {
                if (c + 1 < n - tmp / 4)
                    c++;
                else
                    tmp++, r++;
            }
            else if (tmp % 4 == 1)
            {
                if (r + 1 < m - tmp / 4)
                    r++;
                else
                    tmp++, c--;
            }
            else if (tmp % 4 == 2)
            {
                if (c - 1 >= tmp / 4)
                    c--;
                else
                    tmp++, r--;
            }
            else if (tmp % 4 == 3)
            {
                if (r - 1 >= tmp / 4 + 1)
                    r--;
                else
                    tmp++, c++;
            }
        }
        return res;
    }
};
// @lc code=end

