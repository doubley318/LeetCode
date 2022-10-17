/*
 * @lc app=leetcode.cn id=886 lang=cpp
 *
 * [886] 可能的二分法
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> dis;
    vector<int> color;

    bool dfs(int i, int i_color)
    {
        color[i] = i_color;
        for (auto x : dis[i])
        {
            if (color[x] == i_color)
                return false;
            else if (color[x] == 0)
            {
                if (!dfs(x, -i_color))
                    return false;
            }
        }
        return true;
    }

    bool possibleBipartition(int n, vector<vector<int>> &dislikes)
    {
        dis = vector<vector<int>>(n + 1);
        color = vector<int>(n + 1, 0);
        // 先将每个人的不喜欢列成一个二维数组
        for (auto i : dislikes)
        {
            dis[i[0]].push_back(i[1]);
            dis[i[1]].push_back(i[0]);
        }
        // 对每个人进行操作
        for (int i = 1; i <= n; i++)
        {
            // 如果那个人没有被分组
            if (color[i] == 0)
            {
                // 对那个人进行分组，分为组1，如果冲突则失败
                if (!dfs(i, 1))
                    return false;
                // 为什么不考虑分组为-1呢？
                // 因为是深度优先遍历，所以只要是相关联的人都会被遍历起来
                // 那么第一个人无论是1还是-1都无所谓
                // 因为他是最开始的，他不会受到比他更先的人的影响。
            }
        }
        return true;
    }
};
// @lc code=end
