/*
 * @lc app=leetcode.cn id=172 lang=cpp
 *
 * [172] 阶乘后的零
 */

// @lc code=start
class Solution {
public:
    int trailingZeroes(int n) {
        int ret = 0, mark = 5;
        while (mark <= n)
        {
            ret = ret + n / mark;
            mark = mark * 5;
        }
        return ret;
    }
};
// @lc code=end

