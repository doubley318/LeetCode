/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为 K 的子数组
 */

// @lc code=start
class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> sum;
        int res = 0, tmp = 0;
        sum[0] = 1;
        for (int &i : nums)
        {
            tmp += i;
            if (sum.find(tmp - k) != sum.end())
            {
                res += sum[tmp - k];
            }
            sum[tmp]++;
        }
        return res;
    }
};
// @lc code=end
