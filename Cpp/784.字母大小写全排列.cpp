/*
 * @lc app=leetcode.cn id=784 lang=cpp
 *
 * [784] 字母大小写全排列
 */

// @lc code=start
class Solution
{
public:
    vector<string> letterCasePermutation(string s)
    {
        int l = 0;
        vector<string> ret;
        ret.push_back(s);
        while (l != s.size())
        {
            int t = ret.size();
            while (l < s.size() && s[l] <= '9')
                l++;
            if (l == s.size())
                return ret;
            for (int i = 0; i < t; i++)
            {
                string tmp_s = ret[i];
                tmp_s[l] = tmp_s[l] <= 'Z' ? tmp_s[l] + 32 : tmp_s[l] - 32;
                ret.push_back(tmp_s);
            }
            l++;
        }
        return ret;
    }
};
// @lc code=end
