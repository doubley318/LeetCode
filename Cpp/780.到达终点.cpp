/*
 * @lc app=leetcode.cn id=780 lang=cpp
 *
 * [780] 到达终点
 */

// @lc code=start
class Solution
{
public:
    bool reachingPoints(int sx, int sy, int tx, int ty)
    {
        while (tx >= sx && ty >= sy)
        {
            if (tx == sx && ty == sy)
                return true;
            else if (tx == ty)
                return false;
            int a = tx, b = ty;
            if (a > b)
                tx = a - b * ((a - sx) / b);
            else
                ty = b - a * ((b - sy) / a);
            if (a == tx && b == ty)
                return false;
        }
        return false;
    }
};
// @lc code=end
