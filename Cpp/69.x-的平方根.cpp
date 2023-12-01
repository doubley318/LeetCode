/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根 
 */

// @lc code=start
class Solution {
public:
    int mySqrt(int x)
    {
        int l = 0, r = 46340;
        int m;
        while (l <= r && l <= 46340)
        {
            m = (l + r) / 2;
            if (m * m <= x)
                l = m + 1;
            else
                r = m - 1;
        }
        return l - 1;
    }
};
// @lc code=end

