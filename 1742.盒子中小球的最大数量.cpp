/*
 * @lc app=leetcode.cn id=1742 lang=cpp
 *
 * [1742] 盒子中小球的最大数量
 */

// @lc code=start
class Solution
{
public:
    int fun(int a)
    {
        int ret = 0;
        while (a > 0)
        {
            ret += a % 10;
            a /= 10;
        }
        return ret;
    }

    int countBalls(int lowLimit, int highLimit)
    {
        vector<int> he(50, 0);
        for (int i = lowLimit; i <= highLimit; i++)
        {
            he[fun(i)]++;
        }
        int ret = 0;
        for (int i = 0; i < 50; i++)
        {
            ret = ret > he[i] ? ret : he[i];
        }
        return ret;
    }
};
// @lc code=end
