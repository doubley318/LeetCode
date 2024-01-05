/*
 * @lc app=leetcode.cn id=1671 lang=cpp
 *
 * [1671] 得到山形数组的最少删除次数
 */

// @lc code=start
class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums)
    {
        // dp
        // 假设以nums[i]为山峰
        int n = nums.size();
        vector<int> dp1(n, 0);
        vector<int> dp2(n, 0);
        for (int i = 0; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (nums[i] > nums[j]) {
                    dp1[i] = max(dp1[j] + 1, dp1[i]);
                }
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] > nums[j]) {
                    dp2[i] = max(dp2[j] + 1, dp2[i]);
                }
            }
        }
        int ret = 0;
        for (int i = 0; i < n; i++) {
            if (dp1[i] != 0 && dp2[i] != 0)
                ret = max(ret, dp1[i] + dp2[i]);
        }
        return n - ret - 1;
    }
};
// @lc code=end
