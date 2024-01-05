/*
 * @lc app=leetcode.cn id=1901 lang=cpp
 *
 * [1901] 寻找峰值 II
 */

// @lc code=start
class Solution {
public:
    int findPeak(vector<int>& nums, int l, int r)
    {
        while (l < r) {
            int m = (l + r) / 2;
            if (nums[m] < nums[m + 1]) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        return l;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat)
    {
        int row = mat.size(), col = mat[0].size();
        int l = 0, r = col - 1, x = 0;
        int times = 250000;
        while (times > 0) {
            int m = findPeak(mat[x], l, r);
            int up = -1, down = -1, now = mat[x][m];
            if (x > 0) {
                up = mat[x - 1][m];
            }
            if (x < row - 1) {
                down = mat[x + 1][m];
            }
            if (up < now && down < now) {
                return { x, m };
            }
            if (down > up) {
                x++;
            } else {
                x--;
            }
            if (m < col - 1 && mat[x][m] < mat[x][m + 1]) {
                l = m + 1;
                r = col - 1;
            } else if (m > 0 && mat[x][m] < mat[x][m - 1]) {
                l = 0;
                r = m;
            } else {
                l = m;
                r = m;
            }
            times--;
        }
        return { -1, -1 };
    }
};
// @lc code=end
