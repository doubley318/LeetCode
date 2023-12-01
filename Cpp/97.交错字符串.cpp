/*
 * @lc app=leetcode.cn id=97 lang=cpp
 *
 * [97] 交错字符串
 */

// @lc code=start
class Solution
{
public:
    bool isInterleave1(string s1, string s2, string s3)
    {
        if (s1.size() + s2.size() != s3.size())
            return false;
        if (s1.size() == s2.size() && s1.size() == 0)
            return true;
        bool ans = false;
        if (s1.size() > 0 && s1[0] == s3[0])
            ans = isInterleave1(s1.substr(1), s2, s3.substr(1));
        if (ans)
            return true;
        if (s2.size() > 0 && s2[0] == s3[0])
            ans = isInterleave1(s1, s2.substr(1), s3.substr(1));
        return ans;
    }

    bool isInterleave(string s1, string s2, string s3)
    {
        if (s1.length() + s2.length() != s3.length())
            return false;
        vector<bool> dp(s2.length() + 1, true);
        for (int i = 1; i <= s2.length(); i++)
            dp[i] = dp[i - 1] && (s2[i - 1] == s3[i - 1]);
        for (int i = 0; i < s1.length(); i++)
        {
            dp[0] = dp[0] && (s1[i] == s3[i]);
            for (int j = 1; j <= s2.length(); j++)
                dp[j] = dp[j - 1] && (s2[j - 1] == s3[i + j]) || dp[j] && (s1[i] == s3[i + j]);
        }
        return dp[s2.length()];
    }
};
// @lc code=end
