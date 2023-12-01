/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
class Solution {
public:
    vector<string> generateParenthesis(int n)
    {
        vector<vector<string>> dp(n + 1);
        if (n == 0)
            return dp[0];
        dp[0] = {""};
        dp[1].push_back("()");
        for (int i = 1; i < n; i++)
            for (int j = 0; j <= i; j++)
                for (int k = 0; k < dp[j].size(); k++)
                    for (int l = 0; l < dp[i - j].size(); l++)
                        dp[i + 1].push_back("(" + dp[j][k] + ")" + dp[i - j][l]);
        return dp[n];
    }
};
// @lc code=end

