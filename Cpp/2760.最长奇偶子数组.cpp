/*
 * @lc app=leetcode.cn id=2760 lang=cpp
 *
 * [2760] 最长奇偶子数组
 */

// @lc code=start
class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold)
    {
        int ret = 0;
        int n = nums.size();
        for (int l = 0; l < n; l++) {
            if (nums[l] % 2 == 0 && nums[l] <= threshold) {
                int r = l + 1;
                while (r < n && nums[r] <= threshold && (nums[r - 1] % 2) != (nums[r] % 2)) {
                    r++;
                }
                ret = max(ret, r - l);
                l = r - 1;
            }
        }
        return ret;
    }
};
// @lc code=end
