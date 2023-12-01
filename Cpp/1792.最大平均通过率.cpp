/*
 * @lc app=leetcode.cn id=1792 lang=cpp
 *
 * [1792] 最大平均通过率
 */

// @lc code=start
class Solution
{
public:
    struct cmp
    {
        bool operator()(pair<double, int> a, pair<double, int> b)
        {
            return a.first < b.first;
        }
    };

    double maxAverageRatio(vector<vector<int>> &classes, int extraStudents)
    {
        priority_queue<pair<double, int>, vector<pair<double, int>>, cmp> pq;
        int n = classes.size();
        for (int i = 0; i < n; i++)
        {
            pq.push({1.0 * (classes[i][1] - classes[i][0]) / (1.0 * (classes[i][1] + 1) * classes[i][1]), i});
        }
        for (int i = 0; i < extraStudents; i++)
        {
            int j = pq.top().second;
            pq.pop();
            classes[j][0]++;
            classes[j][1]++;
            pq.push({1.0 * (classes[j][1] - classes[j][0]) / (1.0 * (classes[j][1] + 1) * classes[j][1]), j});
        }
        double res = 0;
        for (int i = 0; i < n; i++)
        {
            res += 1.0 * classes[i][0] / classes[i][1];
        }
        return res / n;
    }
};
// @lc code=end
