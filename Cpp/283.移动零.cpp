/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int l = 0;
        int r = 0;
        while (l < nums.size() && r < nums.size())
        {
            while (l < nums.size() && nums[l] != 0)
                l++;
            r = l;
            while (r < nums.size() && nums[r] == 0)
                r++;
            if (l == nums.size() || r == nums.size())
                return;
            swap(nums[l], nums[r]);
        }
    }
};
// @lc code=end
