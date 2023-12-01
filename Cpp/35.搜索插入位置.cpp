/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */

// @lc code=start
class Solution {
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int l = 0, r = nums.size() - 1;
        while (l <= r)
        {
            if (nums[(l + r) / 2] == target)
                return (l + r) / 2;
            if (nums[(l + r) / 2] < target)
                l = (l + r) / 2 + 1;
            else
                r = (l + r) / 2 - 1;
        }
        return l;
    }
};
// @lc code=end

