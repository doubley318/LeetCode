/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        if (nums.size() == 0)
            return vector<int>{-1, -1};
        int l = searchnum(nums, target, true);
        int r = searchnum(nums, target, false) - 1;
        if (l <= r && r < nums.size() && r >= 0 && nums[r] == target && nums[l] == target)
            return vector<int>{l, r};
        return vector<int>{-1, -1};
    }

    int searchnum(vector<int> &nums, int target, bool left)
    {
        int l = 0, r = nums.size() - 1, res = nums.size();
        while (l <= r)
        {
            int m = (l + r) / 2;
            if ((nums[m] > target) || (left && nums[m] >= target))
            {
                r = m - 1;
                res = m;
            }
            else
                l = m + 1;
        }
        return res;
    }
};
// @lc code=end
