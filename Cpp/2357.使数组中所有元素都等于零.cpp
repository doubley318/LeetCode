/*
 * @lc app=leetcode.cn id=2357 lang=cpp
 *
 * [2357] 使数组中所有元素都等于零
 */

// @lc code=start
class Solution
{
public:
    int minimumOperations(vector<int> &nums)
    {
        vector<int> tmp(105, 0);
        for (int i : nums)
        {
            if (i != 0)
                tmp[i]++;
        }
        int ret = 0;
        for (int i = 1; i <= 100; i++)
        {
            if (tmp[i] != 0)
                ret++;
        }
        return ret;
    }
};
// @lc code=end
