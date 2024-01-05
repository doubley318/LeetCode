/*
 * @lc app=leetcode.cn id=1954 lang=cpp
 *
 * [1954] 收集足够苹果的最小花园周长
 */

// @lc code=start
class Solution {
public:
    long long fun(long long x)
    {
        return 4 * x * (x + 1) * (x + 1) - 2 * x * (x + 1);
    }

    long long minimumPerimeter(long long neededApples)
    {
        // 左上角的边长为x，数量*4-x*4
        long long l = 1, r = 100000;
        while (l < r) {
            long long m = (l + r) / 2;
            long long tmp = fun(m);
            if (tmp < neededApples) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        return 8 * l;
    }
};
// @lc code=end
