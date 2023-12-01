/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */

// @lc code=start
class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for (int i = 0; i < s.size(); i++)
        {
            for (int j = 0; j <= i; j++)
            {
                if (!dp[j])
                    continue;
                bool tmp = false;
                for (int k = 0; k < wordDict.size(); k++)
                {
                    if (s.substr(j, i - j + 1) == wordDict[k])
                    {
                        tmp = true;
                        break;
                    }
                }
                if (tmp == true)
                {
                    dp[i + 1] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};
// @lc code=end
