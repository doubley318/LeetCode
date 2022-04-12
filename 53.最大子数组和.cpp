/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int dp = nums[0];
        int ans = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > dp && dp <= 0)
                dp = nums[i];
            else
                dp = dp + nums[i];
            if (ans < dp)
                ans = dp;
        }
        return ans;
    }
};
// @lc code=end

