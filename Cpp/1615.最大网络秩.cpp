/*
 * @lc app=leetcode.cn id=1615 lang=cpp
 *
 * [1615] 最大网络秩
 */

// @lc code=start
class Solution
{
public:
    int maximalNetworkRank(int n, vector<vector<int>> &roads)
    {

        vector<vector<int>> mmm(n, vector<int>(n, 0));
        for (int i = 0; i < roads.size(); i++)
        {
            mmm[roads[i][0]][roads[i][1]] = 1;
            mmm[roads[i][1]][roads[i][0]] = 1;
        }
        vector<int> record(n, 0);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                record[i] += mmm[i][j];
            }
        }
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < n; i++)
        {
            pq.push(record[i]);
            if (pq.size() > 2)
                pq.pop();
        }
        int lager = pq.top();
        pq.pop();
        int litte = pq.top();
        pq.pop();
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            if (record[i] == lager)
                for (int j = i + 1; j < n; j++)
                {
                    if (record[j] == litte)
                    {
                        res = max(lager + litte - mmm[i][j], res);
                    }
                }
            else if (record[i] == litte)
                for (int j = i + 1; j < n; j++)
                {
                    if (record[j] == lager)
                    {
                        res = max(lager + litte - mmm[i][j], res);
                    }
                }
        }
        return res;
    }
};
// @lc code=end
