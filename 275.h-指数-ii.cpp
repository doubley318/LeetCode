/*
 * @lc app=leetcode.cn id=275 lang=cpp
 *
 * [275] H 指数 II
 */

// @lc code=start
class Solution
{
public:
    int hIndex(vector<int> &citations)
    {
        int l = 0, r = citations.size() - 1;
        int m = (l + r) / 2, n = citations.size();
        while (l <= r)
        {
            m = (l + r) / 2;
            if (citations[m] >= n - m)
            {
                r = m - 1;
            }
            else if (citations[m] < n - m)
            {
                l = m + 1;
            }
        }
        return n - l;
    }
};
// @lc code=end
