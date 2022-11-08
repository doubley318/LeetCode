/*
 * @lc app=leetcode.cn id=724 lang=cpp
 *
 * [724] 寻找数组的中心下标
 */

// @lc code=start
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
        vector<int> sum(nums.size() + 1, 0);
        sum[1] = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            sum[i + 1] = sum[i] + nums[i];
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (sum[i] == sum[sum.size() - 1] - sum[i + 1])
                return i;
        }
        return -1;
    }
};
// @lc code=end

