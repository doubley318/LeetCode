/*
 * @lc app=leetcode.cn id=915 lang=cpp
 *
 * [915] 分割数组
 */

// @lc code=start
class Solution
{
public:
    int partitionDisjoint(vector<int> &nums)
    {
        int ret = 0;
        int maxleft = nums[0];
        int maxall = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            maxall = max(nums[i], maxall);
            if (maxleft > nums[i])
            {
                ret = i;
                maxleft = maxall;
            }
        }
        return ret + 1;
    }
};
// @lc code=end
