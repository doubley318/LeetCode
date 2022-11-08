/*
 * @lc app=leetcode.cn id=1480 lang=cpp
 *
 * [1480] 一维数组的动态和
 */

// @lc code=start
class Solution
{
public:
    vector<int> runningSum(vector<int> &nums)
    {
        vector<int> ret(nums.size(), 0);
        ret[0] = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            ret[i] = ret[i - 1] + nums[i];
        }
        return ret;
    }
};
// @lc code=end
