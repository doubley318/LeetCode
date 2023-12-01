/*
 * @lc app=leetcode.cn id=334 lang=cpp
 *
 * [334] 递增的三元子序列
 */

// @lc code=start
class Solution
{
public:
    bool increasingTriplet(vector<int> &nums)
    {
        int s = INT_MAX;
        int m = INT_MAX;
        if (nums.size() < 3)
            return false;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] <= s)
                s = nums[i];
            else if (nums[i] <= m)
                m = nums[i];
            else
                return true;
        }
        return false;
    }
};
// @lc code=end
