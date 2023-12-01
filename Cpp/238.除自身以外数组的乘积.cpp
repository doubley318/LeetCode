/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] 除自身以外数组的乘积
 */

// @lc code=start
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        vector<int> ret(nums.size(), 1);
        int tmp = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            ret[i] = tmp;
            tmp = tmp * nums[i];
        }
        tmp = 1;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            ret[i] = tmp * ret[i];
            tmp = tmp * nums[i];
        }
        return ret;
    }
};
// @lc code=end
