/*
 * @lc app=leetcode.cn id=1375 lang=cpp
 *
 * [1375] 二进制字符串前缀一致的次数
 */

// @lc code=start
class Solution
{
public:
    int numTimesAllBlue(vector<int> &flips)
    {
        long sum = 0, n = flips.size(), res = 0;
        for (long i = 1; i < n + 1; i++)
        {
            sum += flips[i - 1];
            if (sum == i * (i + 1) / 2)
                res++;
        }
        return res;
    }
};
// @lc code=end
