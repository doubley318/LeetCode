/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
class Solution {
public:
    int search(vector<int> &nums, int target)
    {
        if (nums.size() == 0)
            return 0;
        int is_l = 0;
        int tmp;
        int l = 0, r = nums.size() - 1;
        if (nums[0] <= target)
        {
            is_l = 1;
            tmp = nums[l];
        }
        else
            tmp = nums[r];
        int m;
        while (l <= r)
        {
            m = (l + r) / 2;
            if (nums[m] == target)
                return m;
            if (is_l)
            {
                if (nums[m] > target)
                    r = m - 1;
                else
                {
                    if (nums[m] < tmp)
                        r = m - 1;
                    else
                        l = m + 1;
                }
            }
            else
            {
                if (nums[m] < target)
                    l = m + 1;
                else
                {
                    if (nums[m] > tmp)
                        l = m + 1;
                    else
                        r = m - 1;
                }
            }
        }
        return -1;
    }
};
// @lc code=end

