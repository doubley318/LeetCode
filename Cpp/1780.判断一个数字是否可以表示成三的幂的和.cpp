/*
 * @lc app=leetcode.cn id=1780 lang=cpp
 *
 * [1780] 判断一个数字是否可以表示成三的幂的和
 */

// @lc code=start
class Solution
{
public:
    bool checkPowersOfThree(int n)
    {
        vector<int> num(15, 1);
        for (int i = 1; i < 15; i++)
            num[i] = 3 * num[i - 1];
        for (int i = 14; i >= 0; i--)
        {
            if (n >= num[i])
                n = n - num[i];
        }
        return n == 0;
    }
};
// @lc code=end
