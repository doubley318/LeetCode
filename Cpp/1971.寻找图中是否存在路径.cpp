/*
 * @lc app=leetcode.cn id=1971 lang=cpp
 *
 * [1971] 寻找图中是否存在路径
 */

// @lc code=start
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        vector<vector<int>> m = vector<vector<int>>(n);
        for (int i = 0; i < edges.size(); i++)
        {
            m[edges[i][0]].push_back(edges[i][1]);
            m[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> point(n, 0);
        stack<int> sta;
        if (source == destination)
            return true;
        sta.push(source);
        point[source] = 1;
        while (!sta.empty())
        {
            int t = sta.top();
            sta.pop();
            for (int i = 0; i < m[t].size(); i++)
            {
                if (point[m[t][i]] == 0)
                {
                    sta.push(m[t][i]);
                    point[m[t][i]] = 1;
                }
                if (m[t][i] == destination)
                    return true;
            }
        }
        return false;
    }
};
// @lc code=end

