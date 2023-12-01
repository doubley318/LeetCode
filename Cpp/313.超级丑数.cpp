/*
 * @lc app=leetcode.cn id=313 lang=cpp
 *
 * [313] 超级丑数
 */

// @lc code=start
class Solution
{
public:
    int nthSuperUglyNumber(int n, vector<int> &primes)
    {
        vector<int> dp(n, 0);
        vector<int> point(primes.size(), 0);
        vector<long long> nums(primes.size(), 0);
        for (int i = 0; i < primes.size(); i++)
        {
            nums[i] = primes[i];
        }
        dp[0] = 1;
        for (int i = 1; i < n; i++)
        {
            long long tmp = INT_MAX;
            for (int j = 0; j < point.size(); j++)
            {
                tmp = min(tmp, nums[j]);
            }
            dp[i] = (int)tmp;
            for (int j = 0; j < point.size(); j++)
            {
                if (tmp == nums[j])
                {
                    point[j]++;
                    nums[j] = (long long)primes[j] * dp[point[j]];
                }
            }
        }
        return dp[n - 1];
    }
};
// @lc code=end
