/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

// @lc code=start
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int a = 0, b = 0, c = 0;
        b = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            c = max(a + nums[i], b);
            a = b;
            b = c;
        }
        return b;
    }
};
// @lc code=end
