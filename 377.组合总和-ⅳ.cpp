/*
 * @lc app=leetcode.cn id=377 lang=cpp
 *
 * [377] 组合总和 Ⅳ
 */

// @lc code=start
class Solution
{
public:
    int combinationSum4(vector<int> &nums, int target)
    {
        vector<int> dp(target + 1);
        dp[0] = 1;
        for (int i = 1; i <= target; i++)
        {
            for (int j : nums)
            {
                if (j <= i && dp[i - j] < INT_MAX - dp[i])
                    dp[i] += dp[i - j];
            }
        }
        return dp[target];
    }
};
// @lc code=end
