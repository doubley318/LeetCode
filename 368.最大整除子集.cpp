/*
 * @lc app=leetcode.cn id=368 lang=cpp
 *
 * [368] 最大整除子集
 */

// @lc code=start
class Solution
{
public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<int> dp(nums.size(), 1);
        int max_size = 0, max_value;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] % nums[j] == 0)
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            if (max_size < dp[i])
            {
                max_size = dp[i];
                max_value = nums[i];
            }
        }
        vector<int> ret;
        for (int i = nums.size() - 1; i >= 0 && max_size > 0; i--)
        {
            if (dp[i] == max_size && max_value % nums[i] == 0)
            {
                ret.push_back(nums[i]);
                max_value = nums[i];
                max_size--;
            }
        }
        return ret;
    }
};
// @lc code=end
