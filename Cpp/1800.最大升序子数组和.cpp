/*
 * @lc app=leetcode.cn id=1800 lang=cpp
 *
 * [1800] 最大升序子数组和
 */

// @lc code=start
class Solution
{
public:
    int maxAscendingSum(vector<int> &nums)
    {
        if (nums.size() == 1)
            return nums[0];
        int sum = 0, tmp = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > nums[i - 1])
                tmp += nums[i];
            else
            {
                sum = sum > tmp ? sum : tmp;
                tmp = nums[i];
            }
        }
        sum = sum > tmp ? sum : tmp;
        return sum;
    }
};
// @lc code=end
