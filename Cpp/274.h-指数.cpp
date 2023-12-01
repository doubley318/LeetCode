/*
 * @lc app=leetcode.cn id=274 lang=cpp
 *
 * [274] H 指数
 */

// @lc code=start
class Solution
{
public:
    int hIndex(vector<int> &citations)
    {
        int n = citations.size();
        vector<int> tmp(n + 1);
        for (int i : citations)
        {
            if (i >= n)
                tmp[n]++;
            else
                tmp[i]++;
        }
        int ret = 0;
        for (int i = n; i >= 0; i--)
        {
            ret = ret + tmp[i];
            if (ret >= i)
            {
                ret = i;
                break;
            }
        }
        return ret;
    }
};
// @lc code=end
