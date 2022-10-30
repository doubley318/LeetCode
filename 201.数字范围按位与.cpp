/*
 * @lc app=leetcode.cn id=201 lang=cpp
 *
 * [201] 数字范围按位与
 */

// @lc code=start
class Solution
{
public:
    int rangeBitwiseAnd(int left, int right)
    {
        int ret = 0;
        while (left < right)
        {
            left = left >> 1;
            right = right >> 1;
            ret++;
        }
        return left << ret;
    }
};
// @lc code=end
