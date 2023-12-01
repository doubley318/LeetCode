/*
 * @lc app=leetcode.cn id=2011 lang=cpp
 *
 * [2011] 执行操作后的变量值
 */

// @lc code=start
class Solution
{
public:
    int finalValueAfterOperations(vector<string> &operations)
    {
        int n = operations.size();
        int ret = 0;
        for (int i = 0; i < n; i++)
        {
            if (operations[i][1] == '-')
                --ret;
            else
                ++ret;
        }
        return ret;
    }
};
// @lc code=end
