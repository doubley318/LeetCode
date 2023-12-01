/*
 * @lc app=leetcode.cn id=80 lang=cpp
 *
 * [80] 删除有序数组中的重复项 II
 */

// @lc code=start
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.size() <= 2)
            return nums.size();
        int l = 2, r = 2;
        for (; r < nums.size(); r++)
            if (nums[r] != nums[l - 2])
                nums[l] = nums[r], l++;
        return l;
    }
};
// @lc code=end
