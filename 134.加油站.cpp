/*
 * @lc app=leetcode.cn id=134 lang=cpp
 *
 * [134] 加油站
 */

// @lc code=start
class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int res = 0, sum = 0, tmp_sum = 0, tmp;
        for (int i = 0; i < gas.size(); i++)
        {
            tmp = gas[i] - cost[i];
            sum += tmp;
            if (tmp_sum + tmp < 0)
                res = (i + 1) % gas.size(), tmp_sum = 0;
            else
                tmp_sum = tmp_sum + tmp;
        }
        if (sum < 0)
            return -1;
        return res;
    }
};
// @lc code=end
