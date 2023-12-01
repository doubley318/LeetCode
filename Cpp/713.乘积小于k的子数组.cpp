/*
 * @lc app=leetcode.cn id=713 lang=cpp
 *
 * [713] 乘积小于K的子数组
 */

// @lc code=start
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int l = 0, r = 0, ans = 0;
        long long sum = 1;
        while (r < nums.size())
        {
            if (l == r)
            {
                sum = nums[l];
                if (sum >= k)
                    l++, r++, sum = 1;
                else
                    ans++, r++;
                continue;
            }
            sum = sum * nums[r];
            if (sum >= k)
                sum = sum / nums[l] / nums[r], l++;
            else
            {
                ans = ans + r - l + 1;
                r++;
            }
        }
        return ans;
    }
};
// @lc code=end

