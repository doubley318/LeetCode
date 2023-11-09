/*
 * @lc app=leetcode.cn id=2477 lang=cpp
 *
 * [2477] 到达首都的最少油耗
 */

// @lc code=start
class Solution
{
public:
    int s = 0;
    long long ans = 0;

    long long dfs(vector<vector<int>> &edges, int city, int fcity)
    {
        long long ret = 1;
        for (int i = 0; i < edges[city].size(); i++)
        {
            if (edges[city][i] != fcity)
                ret += dfs(edges, edges[city][i], city);
        }
        if (city != 0)
            ans += (s + ret - 1) / s;
        return ret;
    }

    long long minimumFuelCost(vector<vector<int>> &roads, int seats)
    {
        int n = roads.size();
        vector<vector<int>> edge(n + 1, vector<int>());
        s = seats;
        for (int i = 0; i < n; i++)
        {
            edge[roads[i][0]].push_back(roads[i][1]);
            edge[roads[i][1]].push_back(roads[i][0]);
        }
        dfs(edge, 0, -1);
        return ans;
    }
};
// @lc code=end
