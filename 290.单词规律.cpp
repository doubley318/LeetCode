/*
 * @lc app=leetcode.cn id=290 lang=cpp
 *
 * [290] 单词规律
 */

// @lc code=start
class Solution
{
public:
    bool wordPattern(string pattern, string s)
    {
        map<char, string> my_map;
        map<string, char> inverse_map;
        int l = 0;
        for (int i = 0; i < s.size(); i++)
        {
            int tmp = i;
            while (i < s.size() && s[i] != ' ')
            {
                i++;
            }
            string t = s.substr(tmp, i - tmp);
            char a = pattern[l];
            if (my_map.find(a) != my_map.end())
            {
                if (my_map[a] != t)
                    return false;
            }
            else
            {
                if (inverse_map.find(t) != inverse_map.end())
                    return false;
                my_map[a] = t;
                inverse_map[t] = a;
            }
            l++;
        }
        if (l != pattern.size())
            return false;
        return true;
    }
};
// @lc code=end
