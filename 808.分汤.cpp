/*
 * @lc app=leetcode.cn id=808 lang=cpp
 *
 * [808] 分汤
 */

// @lc code=start
class Solution
{
public:
    vector<vector<double>> dp;
    double dfs(int a, int b)
    {
        if (a <= 0 && b <= 0)
            return 0.5;
        else if (a <= 0)
            return 1;
        else if (b <= 0)
            return 0;
        if (dp[a][b] == 0)
            dp[a][b] = (dfs(a - 1, b - 3) + dfs(a - 2, b - 2) + dfs(a - 3, b - 1) + dfs(a - 4, b)) / 4;
        return dp[a][b];
    }

    double soupServings(int n)
    {
        int num = (int)ceil((double)n / 25);
        if (n > 4450)
            return 1;
        dp = vector<vector<double>>(num + 1, vector<double>(num + 1, 0));
        return dfs(num, num);
    }
};
// @lc code=end
