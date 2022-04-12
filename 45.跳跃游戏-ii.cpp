/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start
class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int location = 0;
        int ans = 0;
        int max_step = nums[0];
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (location == 0)
            {
                location = max(max_step, nums[i]);
                ans++;
            }
            else if (max_step < nums[i])
                max_step = nums[i];
            max_step--;
            location--;
        }
        return ans;
    }
};
// @lc code=end
