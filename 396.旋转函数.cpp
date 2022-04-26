/*
 * @lc app=leetcode.cn id=396 lang=cpp
 *
 * [396] 旋转函数
 */

// @lc code=start
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int sum = 0, tmp = 0;
        for (int i = 0; i < nums.size(); i++)
            sum = sum + nums[i], tmp = tmp + nums[i] * i;
        int ans = tmp;
        for (int i = 1; i < nums.size(); i++)
            tmp = tmp + sum - nums.size() * nums[nums.size() - i], ans = max(ans, tmp);
        return ans;
    }
};
// @lc code=end

