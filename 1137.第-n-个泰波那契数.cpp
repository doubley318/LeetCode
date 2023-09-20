/*
 * @lc app=leetcode.cn id=1137 lang=cpp
 *
 * [1137] 第 N 个泰波那契数
 */

// @lc code=start
class Solution {
public:
    int tribonacci(int n)
    {
        vector<int> tbi = { 0, 1, 1 };
        for (int i = 0; i <= n - 3; i++) {
            tbi[i % 3] = tbi[0] + tbi[1] + tbi[2];
        }
        return tbi[n % 3];
    }
};
// @lc code=end
