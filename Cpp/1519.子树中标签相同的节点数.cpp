/*
 * @lc app=leetcode.cn id=1519 lang=cpp
 *
 * [1519] 子树中标签相同的节点数
 */

// @lc code=start
class Solution
{
public:
    void dfs(int node, int pre, vector<vector<int>> &trees, vector<vector<int>> &lables)
    {
        if (trees[node].size() == 0)
            return;
        for (int i = 0; i < trees[node].size(); i++)
        {
            if (trees[node][i] == pre)
                continue;
            dfs(trees[node][i], node, trees, lables);
            for (int j = 0; j < 26; j++)
            {
                lables[node][j] += lables[trees[node][i]][j];
            }
        }
    }

    vector<int> countSubTrees(int n, vector<vector<int>> &edges, string labels)
    {
        vector<vector<int>> myTrees(n);
        vector<vector<int>> myLables(n, vector<int>(26, 0));
        for (int i = 0; i < n - 1; i++)
        {
            myTrees[edges[i][0]].push_back(edges[i][1]);
            myTrees[edges[i][1]].push_back(edges[i][0]);
            myLables[i][labels[i] - 'a']++;
        }
        myLables[n - 1][labels[n - 1] - 'a']++;
        dfs(0, -1, myTrees, myLables);
        vector<int> res(n, 0);
        for (int i = 0; i < n; i++)
        {
            res[i] = myLables[i][labels[i] - 'a'];
        }
        return res;
    }
};
// @lc code=end
