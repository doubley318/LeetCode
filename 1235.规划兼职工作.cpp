/*
 * @lc app=leetcode.cn id=1235 lang=cpp
 *
 * [1235] 规划兼职工作
 */

// @lc code=start
class Solution
{
public:
    int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit)
    {
        int n = startTime.size();
        vector<vector<int>> jobs(n);
        for (int i = 0; i < n; i++)
        {
            jobs[i] = {startTime[i], endTime[i], profit[i]};
        }
        sort(jobs.begin(), jobs.end(), [](const vector<int> &job1, const vector<int> &job2) -> bool
             { return job1[1] < job2[1]; });
        vector<pair<int, int>> dp(startTime.size());
        dp[0] = {jobs[0][1], jobs[0][2]};
        for (int i = 1; i < n; i++)
        {
            int start = jobs[i][0];
            int tmp = 0;
            for (int j = i - 1; j >= 0; j--)
            {
                if (start >= jobs[j][1])
                {
                    tmp = dp[j].second + jobs[i][2];
                    break;
                }
            }
            if (tmp == 0)
                tmp = jobs[i][2];
            dp[i] = {jobs[i][1], max(tmp, dp[i - 1].second)};
        }
        return dp[dp.size() - 1].second;
    }
};
// @lc code=end
