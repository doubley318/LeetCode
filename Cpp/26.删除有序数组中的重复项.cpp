/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.size() <= 1)
            return nums.size();
        int res = 1, tmp = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] != nums[tmp])
            {
                nums[res] = nums[i];
                tmp = i;
                res++;
            }
        }
        return res;
    }
};
// @lc code=end

