/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int tmp = nums[0];
        for (int i = 0; i < nums.size() - 1; i++)
        {
            tmp = max(tmp, nums[i]);
            if (tmp == 0)
                return false;
            tmp--;
        }
        return true;
    }
};
// @lc code=end
