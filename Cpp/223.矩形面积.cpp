/*
 * @lc app=leetcode.cn id=223 lang=cpp
 *
 * [223] 矩形面积
 */

// @lc code=start
class Solution
{
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2)
    {
        int s1 = (ax2 - ax1) * (ay2 - ay1);
        int s2 = (bx2 - bx1) * (by2 - by1);
        int x = (min(ax2, bx2) - max(ax1, bx1)), y = (min(ay2, by2) - max(ay1, by1));
        int c = (x > 0 && y > 0) ? x * y : 0;
        return s1 + s2 - c;
    }
};
// @lc code=end
