/*
 * @lc app=leetcode.cn id=801 lang=cpp
 *
 * [801] 使序列递增的最小交换次数
 */

// @lc code=start
class Solution {
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size(), vector<int>(2, 0));
        dp[0][0] = 0;
        dp[0][1] = 1;
        for (int i = 1; i < nums1.size(); i++)
        {
            if (nums1[i - 1] < nums1[i] && nums2[i - 1] < nums2[i])
            {
                if (nums1[i - 1] < nums2[i] && nums2[i - 1] < nums1[i])
                {
                    dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]);
                    dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + 1;
                }
                else
                {
                    dp[i][0] = dp[i - 1][0];
                    dp[i][1] = dp[i - 1][1] + 1;
                }
            }
            else
            {
                dp[i][0] = dp[i - 1][1];
                dp[i][1] = dp[i - 1][0] + 1;
            }
        }
        return min(dp[nums1.size() - 1][0], dp[nums1.size() - 1][1]);
    }
};
// @lc code=end

