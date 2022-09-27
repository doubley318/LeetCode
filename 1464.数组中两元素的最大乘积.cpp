/*
 * @lc app=leetcode.cn id=1464 lang=cpp
 *
 * [1464] 数组中两元素的最大乘积
 */

// @lc code=start
class Solution {
public:
    int maxProduct(vector<int> &nums)
    {
        int maxnum, second;
        maxnum = nums[0] > nums[1] ? nums[0] : nums[1];
        second = nums[0] <= nums[1] ? nums[0] : nums[1];
        for (int i = 2; i < nums.size(); i++)
        {
            if (second < nums[i])
            {
                if (maxnum <= nums[i])
                {
                    second = maxnum;
                    maxnum = nums[i];
                }
                else
                    second = nums[i];
            }
        }
        return (maxnum - 1) * (second - 1);
    }
};
// @lc code=end

