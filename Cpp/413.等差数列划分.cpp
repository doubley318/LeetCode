/*
 * @lc app=leetcode.cn id=413 lang=cpp
 *
 * [413] 等差数列划分
 */

// @lc code=start
class Solution
{
public:
    int numberOfArithmeticSlices(vector<int> &nums)
    {
        int ret = 0, tmp = 2;
        if (nums.size() <= 2)
            return ret;
        for (int i = 0; i < nums.size() - 2; i++)
        {
            if (nums[i] - nums[i + 1] == nums[i + 1] - nums[i + 2])
                tmp++;
            else
            {
                ret += ((tmp - 2) + 1) * (tmp - 2) / 2;
                tmp = 2;
            }
        }
        ret += ((tmp - 2) + 1) * (tmp - 2) / 2;
        return ret;
    }
};
// @lc code=end
