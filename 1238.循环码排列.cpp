/*
 * @lc app=leetcode.cn id=1238 lang=cpp
 *
 * [1238] 循环码排列
 */

// @lc code=start
class Solution
{
public:
    vector<int> circularPermutation(int n, int start)
    {
        vector<int> tmp(pow(2, n), 0);
        vector<int> ret(pow(2, n), 0);
        tmp[0] = 0;
        tmp[1] = 1;
        int mark = start;
        for (int i = 1; i < n; i++)
        {
            int t = pow(2, i);
            for (int j = 0; j < t; j++)
            {
                tmp[t + j] = t + tmp[t - j - 1];
                if (tmp[t + j] == start)
                    mark = t + j;
            }
        }
        n = pow(2, n);
        for (int i = 0; i < n; i++)
        {
            ret[i] = tmp[(mark + i) % n];
        }
        return ret;
    }
};
// @lc code=end
