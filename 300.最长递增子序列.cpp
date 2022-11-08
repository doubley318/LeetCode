/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */

// @lc code=start
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int ret = 1;
        vector<int> dp(nums.size(), 1);
        for (int i = 1; i < nums.size(); i++)
        {
            int t = 0;
            for (int j = i - 1; j >= 0; j--)
            {
                if (nums[i] > nums[j])
                    t = max(t, dp[j]);
            }
            dp[i] = t + 1;
            ret = max(dp[i], ret);
        }
        return ret;
    }
};
// @lc code=end
