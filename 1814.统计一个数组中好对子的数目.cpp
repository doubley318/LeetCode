/*
 * @lc app=leetcode.cn id=1814 lang=cpp
 *
 * [1814] 统计一个数组中好对子的数目
 */

// @lc code=start
class Solution
{
public:
    int countNicePairs(vector<int> &nums)
    {
        int n = nums.size();
        unordered_map<long long, int> revnum;
        long long res = 0;
        for (int i = 0; i < n; i++)
        {
            long long tmp = 0;
            int t = nums[i];
            while (t > 0)
            {
                tmp = tmp * 10 + t % 10;
                t = t / 10;
            }
            res = res + revnum[nums[i] - tmp]++;
        }
        return res % 1000000007;
    }
};
// @lc code=end
