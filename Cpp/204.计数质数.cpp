/*
 * @lc app=leetcode.cn id=204 lang=cpp
 *
 * [204] 计数质数
 */

// @lc code=start
class Solution
{
public:
    int countPrimes(int n)
    {
        int ans = 0;
        vector<int> primer(n, 1);
        for (int i = 2; i < n; i++)
        {
            if (primer[i] == 1)
            {
                ans++;
                if ((long long)i * i < n)
                    for (int j = i * i; j < n; j += i)
                    {
                        primer[j] = 0;
                    }
            }
        }
        return ans;
    }
};
// @lc code=end
