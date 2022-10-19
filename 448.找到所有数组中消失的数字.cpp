/*
 * @lc app=leetcode.cn id=448 lang=cpp
 *
 * [448] 找到所有数组中消失的数字
 */

// @lc code=start
class Solution
{
public:
    vector<int> findDisappearedNumbers(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); i++)
            nums[abs(nums[i]) - 1] = -abs(nums[abs(nums[i]) - 1]);
        vector<int> ret;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0)
                ret.push_back(i + 1);
        }
        return ret;
    }
};
// @lc code=end
