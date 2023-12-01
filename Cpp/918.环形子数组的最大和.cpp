/*
 * @lc app=leetcode.cn id=918 lang=cpp
 *
 * [918] 环形子数组的最大和
 */

// @lc code=start
class Solution
{
public:
    int maxSubarraySumCircular(vector<int> &nums)
    {
        // 每个元素只能使用一次
        int sum_max = nums[0], tmp_max = 0, tmp_min = 0, sum_min = nums[0], total = 0;
        for (int &i : nums)
        {
            tmp_max = max(tmp_max + i, i);
            sum_max = max(tmp_max, sum_max);
            tmp_min = min(tmp_min + i, i);
            sum_min = min(tmp_min, sum_min);
            total += i;
        }
        return sum_max > 0 ? max(sum_max, total - sum_min) : sum_max;
    }
};
// @lc code=end
