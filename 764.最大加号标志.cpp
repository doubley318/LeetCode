/*
 * @lc app=leetcode.cn id=764 lang=cpp
 *
 * [764] 最大加号标志
 */

// @lc code=start
class Solution
{
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>> &mines)
    {
        vector<vector<int>> dp(n, vector<int>(n, n));
        for (int i = 0; i < mines.size(); i++)
        {
            dp[mines[i][0]][mines[i][1]] = 0;
        }
        for (int i = 0; i < n; i++)
        {
            int left = 0, right = 0, up = 0, down = 0;
            for (int j = 0, k = n - 1; j < n; j++, k--)
            {
                left = dp[i][j] == 0 ? 0 : left + 1;
                right = dp[i][k] == 0 ? 0 : right + 1;
                up = dp[j][i] == 0 ? 0 : up + 1;
                down = dp[k][i] == 0 ? 0 : down + 1;
                dp[i][j] = min(dp[i][j], left);
                dp[i][k] = min(dp[i][k], right);
                dp[j][i] = min(dp[j][i], up);
                dp[k][i] = min(dp[k][i], down);
            }
        }
        int ret = 0;
        for (auto i : dp)
            ret = max(ret, *max_element(i.begin(), i.end()));
        return ret;
    }
};
// @lc code=end
