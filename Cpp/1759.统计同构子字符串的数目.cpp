/*
 * @lc app=leetcode.cn id=1759 lang=cpp
 *
 * [1759] 统计同构子字符串的数目
 */

// @lc code=start
class Solution
{
public:
    int countHomogenous(string s)
    {
        vector<vector<int>> son(26);
        int n = s.size();
        if (n == 1)
            return 1;
        char a = s[0];
        for (int i = 1; i < n; i++)
        {
            int t = 1;
            while (i < n && s[i] == a)
            {
                t++;
                i++;
            }
            son[a - 'a'].push_back(t);
            if (i < n)
                a = s[i];
        }
        if (n >= 2 && s[n - 1] != s[n - 2])
            son[a - 'a'].push_back(1);
        long long ret = 0;
        for (int i = 0; i < 26; i++)
        {
            for (int j : son[i])
            {
                ret = ret + (long long)(j + 1) * j / 2;
            }
        }
        return ret % 1000000007;
    }
};
// @lc code=end
