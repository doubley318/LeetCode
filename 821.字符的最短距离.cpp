/*
 * @lc app=leetcode.cn id=821 lang=cpp
 *
 * [821] 字符的最短距离
 */

// @lc code=start
class Solution
{
public:
    vector<int> shortestToChar(string s, char c)
    {
        vector<int> ans(s.length(), 10000);
        if (s[0] == c)
            ans[0] = 0;
        for (int i = 1; i < s.length(); i++)
        {
            if (c == s[i])
                ans[i] = 0;
            else
                ans[i] = min(ans[i - 1] + 1, ans[i]);
        }
        for (int i = s.length() - 2; i >= 0; i--)
        {
            if (c == s[i])
                ans[i] = 0;
            else
                ans[i] = min(ans[i + 1] + 1, ans[i]);
        }
        return ans;
    }
};
// @lc code=end
