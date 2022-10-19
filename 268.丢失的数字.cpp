/*
 * @lc app=leetcode.cn id=268 lang=cpp
 *
 * [268] 丢失的数字
 */

// @lc code=start
class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int ret = 0;
        for (int i : nums)
            ret = i + ret;
        return ((nums.size() + 1) * nums.size() / 2 - ret);
    }
};
// @lc code=end
