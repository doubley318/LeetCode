/*
 * @lc app=leetcode.cn id=791 lang=cpp
 *
 * [791] 自定义字符串排序
 */

// @lc code=start
class Solution
{
public:
    string customSortString(string order, string s)
    {
        vector<int> r(26, 0);
        for (int i = 0; i < s.size(); i++)
        {
            r[s[i] - 'a']++;
        }
        string ret;
        for (int i = 0; i < order.size(); i++)
        {
            while (r[order[i] - 'a'] != 0)
            {
                ret = ret + order[i];
                r[order[i] - 'a']--;
            }
        }
        for (int i = 0; i < 26; i++)
        {
            char x = i + 'a';
            while (r[i] != 0)
            {
                ret = ret + x;
                r[i]--;
            }
        }
        return ret;
    }
};
// @lc code=end
