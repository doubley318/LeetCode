/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> res;
        per(res, nums, 0, nums.size());
        return res;
    }

    void per(vector<vector<int>> &res, vector<int> &nums, int l, int r)
    {
        if (l == r)
        {
            res.push_back(nums);
            return;
        }
        for (int i = l; i < r; i++)
        {
            swap(nums[l], nums[i]);
            per(res, nums, l + 1, r);
            swap(nums[l], nums[i]);
        }
    }
};
// @lc code=end

