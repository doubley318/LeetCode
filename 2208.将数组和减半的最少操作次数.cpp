/*
 * @lc app=leetcode.cn id=2208 lang=cpp
 *
 * [2208] 将数组和减半的最少操作次数
 */

// @lc code=start
class Solution
{
public:
    int halveArray(vector<int> &nums)
    {
        double sum = 0;
        priority_queue<double> pq;
        for (int &i : nums)
        {
            sum += i;
            pq.push(i);
        }
        int ret = 0;
        double tmp_sum = sum;
        while (tmp_sum > sum / 2)
        {
            double tmp = pq.top();
            pq.pop();
            pq.push(tmp / 2);
            tmp_sum -= tmp / 2;
            ret++;
        }
        return ret;
    }
};
// @lc code=end
