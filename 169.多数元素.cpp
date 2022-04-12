/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */

// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0, ans = nums[0];
        for (int i : nums)
        {
            count += ans == i ? 1 : -1;
            if (count == -1)
                count = 1, ans = i;
        }
        return ans;
    }
};
// @lc code=end

