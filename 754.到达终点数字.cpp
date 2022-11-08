/*
 * @lc app=leetcode.cn id=754 lang=cpp
 *
 * [754] 到达终点数字
 */

// @lc code=start
class Solution
{
public:
    int reachNumber(int target)
    {
        target = abs(target);
        int l = sqrt(target * 2);
        int llen = l * (l + 1) / 2;
        while (llen < target || (llen - target) % 2 == 1)
        {
            l++;
            llen = l * (l + 1) / 2;
        }
        return l;
    }
};
// @lc code=end
