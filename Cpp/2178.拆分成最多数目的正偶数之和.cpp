/*
 * @lc app=leetcode.cn id=2178 lang=cpp
 *
 * [2178] 拆分成最多数目的正偶数之和
 */

// @lc code=start

class Solution
{
public:
    vector<long long> maximumEvenSplit(long long finalSum)
    {
        vector<long long> res;
        if (finalSum & 1)
            return res;
        if (finalSum == 4)
        {
            res.push_back(4);
            return res;
        }
        res.push_back(2);
        long long remain = finalSum - 2;
        while (true)
        {
            long long l = res[res.size() - 1] + 2;
            long long r = remain - l;
            if (l >= r)
                break;
            res.push_back(l);
            remain = r;
        }
        if (remain != 0)
            res.push_back(remain);
        return res;
    }
};
// @lc code=end
