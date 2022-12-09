/*
 * @lc app=leetcode.cn id=775 lang=cpp
 *
 * [775] 全局倒置与局部倒置
 */

// @lc code=start
class Solution
{
public:
    bool isIdealPermutation(vector<int> &nums)
    {
        int tmp = nums[nums.size() - 1];
        for (int i = nums.size() - 3; i >= 0; i--)
        {
            if (tmp < nums[i])
                return false;
            tmp = min(tmp, nums[i + 1]);
        }
        return true;
    }
};
// @lc code=end
