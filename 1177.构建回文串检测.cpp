/*
 * @lc app=leetcode.cn id=1177 lang=cpp
 *
 * [1177] 构建回文串检测
 */

// @lc code=start
class Solution
{
public:
    bool Judge(string &s, int l, int r, int k)
    {
        for (int i = l, j = r; i < j; i++, j--)
        {
            if (s[i] != s[j])
                k--;
        }
        if (k < 0)
            return false;
        else
            return true;
    }

    vector<bool> canMakePaliQueries(string s, vector<vector<int>> &queries)
    {
        int n = queries.size();
        vector<bool> res(n, true);
        for (int i = 0; i < n; i++)
        {
            res[i] = Judge(s, queries[i][0], queries[i][1], queries[i][2]);
        }
        return res;
    }
};
// @lc code=end
