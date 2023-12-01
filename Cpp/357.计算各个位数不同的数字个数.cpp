/*
 * @lc app=leetcode.cn id=357 lang=cpp
 *
 * [357] 计算各个位数不同的数字个数
 */

// @lc code=start
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0)
            return 1;
        if (n == 1)
            return 10;
        int a = 1, b = 10, t = 1;
        for (int i = 2; i <= n; i++)
            t = b, b = b + (b - a) * (11 - i), a = t;
        return b;
    }
};
// @lc code=end

