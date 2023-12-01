/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */

// @lc code=start
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        if (nums.size() == 1)
            return nums[0];
        int cur1 = nums[0], cur2 = 0;
        int pre1 = nums[0], pre2 = nums[1];
        int tmp1 = cur1, tmp2;
        for (int i = 2; i < nums.size() - 1; i++)
        {
            tmp1 = max(cur1 + nums[i], pre1);
            tmp2 = max(cur2 + nums[i], pre2);
            cur1 = pre1;
            pre1 = tmp1;
            cur2 = pre2;
            pre2 = tmp2;
        }
        tmp2 = max(cur2 + nums[nums.size() - 1], pre2);
        return max(tmp1, tmp2);
    }
};
// @lc code=end
