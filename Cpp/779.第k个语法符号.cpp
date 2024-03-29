/*
 * @lc app=leetcode.cn id=779 lang=cpp
 *
 * [779] 第K个语法符号
 */

// @lc code=start
class Solution
{
public:
    int kthGrammar(int n, int k)
    {
        if (n == 1)
            return 0;
        if (kthGrammar(n - 1, (k + 1) / 2) == 0)
        {
            if (k % 2 == 0)
                return 1;
            else
                return 0;
        }
        else
        {
            if (k % 2 == 0)
                return 0;
            else
                return 1;
        }
    }
};
// @lc code=end
