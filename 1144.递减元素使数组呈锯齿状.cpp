/*
 * @lc app=leetcode.cn id=1144 lang=cpp
 *
 * [1144] 递减元素使数组呈锯齿状
 */

// @lc code=start
class Solution
{
public:
    int movesToMakeZigzag(vector<int> &nums)
    {
        int minlocation = 0, n = nums.size();
        if (n == 1)
            return 0;
        int ret = 0;
        if (nums[0] >= nums[1])
            ret += nums[0] - nums[1] + 1;
        for (int i = 2; i < n - 1; i = i + 2)
        {
            int tmp = min(nums[i - 1], nums[i + 1]);
            if (tmp <= nums[i])
                ret += nums[i] - tmp + 1;
        }
        if (n % 2 == 1)
            if (nums[n - 1] >= nums[n - 2])
                ret += nums[n - 1] - nums[n - 2] + 1;
        int ret_ret = 0;
        for (int i = 1; i < n - 1; i = i + 2)
        {
            int tmp = min(nums[i - 1], nums[i + 1]);
            if (tmp <= nums[i])
                ret_ret += nums[i] - tmp + 1;
        }
        if (n % 2 == 0)
            if (nums[n - 1] >= nums[n - 2])
                ret_ret += nums[n - 1] - nums[n - 2] + 1;
        return min(ret, ret_ret);
    }
};
// @lc code=end
