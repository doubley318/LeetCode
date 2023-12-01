/*
 * @lc app=leetcode.cn id=1822 lang=cpp
 *
 * [1822] 数组元素积的符号
 */

// @lc code=start
class Solution
{
public:
    int arraySign(vector<int> &nums)
    {
        int ret = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
                return 0;
            else if (nums[i] < 0)
                ret++;
        }
        return ret % 2 == 0 ? 1 : -1;
    }
};
// @lc code=end
