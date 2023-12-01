/*
 * @lc app=leetcode.cn id=1753 lang=cpp
 *
 * [1753] 移除石子的最大得分
 */

// @lc code=start
class Solution
{
public:
    int maximumScore(int a, int b, int c)
    {
        if (a < b)
            swap(a, b);
        if (a < c)
            swap(a, c);
        if (b + c < a)
            return b + c;
        return (a + b + c) / 2;
    }
};
// @lc code=end
