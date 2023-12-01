/*
 * @lc app=leetcode.cn id=1827 lang=cpp
 *
 * [1827] 最少操作使数组递增
 */

// @lc code=start
class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        int ret = 0, n = nums.size(), pre = nums[0];
        for (int i = 1; i < n; i++)
        {
            if (pre + 1 > nums[i])
            {
                ret = ret + pre + 1 - nums[i];
                nums[i] = pre + 1;
            }
            pre = nums[i];
        }
        return ret;
    }
};
// @lc code=end
