/*
 * @lc app=leetcode.cn id=1752 lang=cpp
 *
 * [1752] 检查数组是否经排序和轮转得到
 */

// @lc code=start
class Solution
{
public:
    bool check(vector<int> &nums)
    {
        int x = 0, n = nums.size();
        for (int i = 1; i < n; i++)
        {
            if (nums[i] < nums[i - 1])
            {
                x = i;
                break;
            }
        }
        if (x == 0)
            return true;
        for (int i = x + 1; i < n; i++)
        {
            if (nums[i] < nums[i - 1])
            {
                return false;
            }
        }
        return nums[0] >= nums[n - 1];
    }
};
// @lc code=end
