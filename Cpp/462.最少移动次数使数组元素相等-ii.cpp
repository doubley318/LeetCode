/*
 * @lc app=leetcode.cn id=462 lang=cpp
 *
 * [462] 最少移动次数使数组元素相等 II
 */

// @lc code=start
class Solution {
public:
    int minMoves2(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int in;
        if (nums.size() % 2 == 1)
            in = nums[nums.size() / 2];
        else
            in = (nums[nums.size() / 2] + nums[nums.size() / 2 - 1]) / 2;
        int ans = 0;
        for (int i : nums)
            ans = abs(in - i) + ans;
        return ans;
    }
};
// @lc code=end

