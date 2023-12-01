/*
 * @lc app=leetcode.cn id=2256 lang=cpp
 *
 * [2256] 最小平均差
 */

// @lc code=start
class Solution
{
public:
    int minimumAverageDifference(vector<int> &nums)
    {
        int n = nums.size();
        int res = INT_MAX;
        long long sum = 0;
        int ret = 0;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
        }
        long long pre = 0;
        for (int i = 0; i < n - 1; i++)
        {
            pre += nums[i];
            int tmp_res = abs(pre / (i + 1) - (sum - pre) / (n - i - 1));
            if (tmp_res < res)
            {
                res = tmp_res;
                ret = i;
            }
        }
        if (sum / n < res)
            return n - 1;
        else
            return ret;
    }
};
// @lc code=end
