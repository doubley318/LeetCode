/*
 * @lc app=leetcode.cn id=1704 lang=cpp
 *
 * [1704] 判断字符串的两半是否相似
 */

// @lc code=start
class Solution
{
public:
    bool halvesAreAlike(string s)
    {
        int len = s.size() / 2;
        unordered_set<char> dictionary = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int l = 0, r = 0;
        for (int i = 0; i < len; i++)
        {
            if (dictionary.count(s[i]))
                l++;
            if (dictionary.count(s[i + len]))
                r++;
        }
        if (l == r)
            return true;
        else
            return false;
    }
};
// @lc code=end
