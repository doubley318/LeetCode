/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int l = 0, r = 0;
        int ret = INT_MAX, sum = 0;
        while (r < nums.size() && l < nums.size())
        {
            sum = sum + nums[r];
            while (sum >= target)
            {
                ret = min(ret, r - l + 1);
                if (ret == 1)
                    return 1;
                sum = sum - nums[l];
                l++;
            }
            r++;
        }
        return ret == INT_MAX ? 0 : ret;
    }
};
// @lc code=end

