/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));
        int tmp = 0, r = 0, c = 0;
        for (int i = 1; i <= n * n; i++)
        {
            ans[r][c] = i;
            if (tmp % 4 == 0)
            {
                if (c + 1 < n - tmp / 4)
                    c++;
                else
                    r++, tmp++;
            }
            else if (tmp % 4 == 1)
            {
                if (r + 1 < n - tmp / 4)
                    r++;
                else
                    c--, tmp++;
            }
            else if (tmp % 4 == 2)
            {
                if (c - 1 >= tmp / 4)
                    c--;
                else
                    r--, tmp++;
            }
            else
            {
                if (r - 1 >= tmp / 4 + 1)
                    r--;
                else
                    c++, tmp++;
            }
        }
        return ans;
    }
};
// @lc code=end

