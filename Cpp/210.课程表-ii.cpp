/*
 * @lc app=leetcode.cn id=210 lang=cpp
 *
 * [210] 课程表 II
 */

// @lc code=start
class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        /*
        vector<vector<int>> edge(numCourses);
        vector<int> degree(numCourses, 0);
        // 入度不为0的点
        unordered_set<int> point;
        vector<int> ret;
        for (int i = 0; i < prerequisites.size(); i++)
        {
            edge[prerequisites[i][0]].push_back(prerequisites[i][1]);
            degree[prerequisites[i][0]]++;
            point.insert(prerequisites[i][0]);
        }
        int tmp = ret.size();
        while (tmp != numCourses)
        {
            for (int i = 0; i < numCourses; i++)
            {
                // 如果这个点的入度为0，说明需要被删除
                if (degree[i] == 0)
                {
                    // 查询是否有其他点依赖于这个点，如果依赖，则其他点入度减一
                    for (auto j = point.begin(); j != point.end(); j++)
                    {
                        // 查询其他点的依赖点
                        for (int k = 0; k < edge[*j].size(); k++)
                        {
                            if (edge[*j][k] == i)
                            {
                                degree[*j]--;
                            }
                        }
                    }
                    ret.push_back(i);
                    degree[i] = -1;
                    if (point.find(i) != point.end())
                        point.erase(i);
                }
            }
            if (tmp == ret.size())
                return {};
            else
                tmp = ret.size();
        }
        return ret;
        */
        // bfs
        vector<int> ret;
        vector<vector<int>> edge(numCourses);
        vector<int> degree(numCourses, 0);
        queue<int> degree_0;
        for (int i = 0; i < prerequisites.size(); i++)
        {
            edge[prerequisites[i][1]].push_back(prerequisites[i][0]);
            degree[prerequisites[i][0]]++;
        }
        for (int i = 0; i < numCourses; i++)
        {
            if (degree[i] == 0)
            {
                degree_0.push(i);
            }
        }
        if (degree_0.empty())
            return ret;
        int tmp = ret.size();
        while (tmp != numCourses)
        {
            int t = degree_0.size();
            for (int i = 0; i < t; i++)
            {
                int d = degree_0.front();
                degree_0.pop();
                ret.push_back(d);
                degree[d] = -1;
                for (int j = 0; j < edge[d].size(); j++)
                {
                    if (--degree[edge[d][j]] == 0)
                        degree_0.push(edge[d][j]);
                }
            }
            if (tmp == ret.size())
                return {};
            else
                tmp = ret.size();
        }
        return ret;
    }
};
// @lc code=end
