/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子数组
 */

// @lc code=start
class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int ret = INT_MIN;
        int imax = 1, imin = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] < 0)
                swap(imax, imin);
            imax = max(imax * nums[i], nums[i]);
            imin = min(imin * nums[i], nums[i]);
            ret = max(imax, ret);
        }
        return ret;
    }
};
// @lc code=end
