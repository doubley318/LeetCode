/*
 * @lc app=leetcode.cn id=961 lang=cpp
 *
 * [961] 在长度 2N 的数组中找出重复 N 次的元素
 */

// @lc code=start
class Solution
{
public:
    int repeatedNTimes(vector<int> &nums)
    {
        int ans = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if (ans != nums[i])
                ans = nums[i];
            else
                return ans;
        }
        ans = nums[0];
        if (ans == nums[2] || ans == nums[3])
            return ans;
        else
            return nums[1];
    }
};
// @lc code=end
