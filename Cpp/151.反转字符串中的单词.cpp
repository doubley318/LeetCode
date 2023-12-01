/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 反转字符串中的单词
 */

// @lc code=start
class Solution
{
public:
    string reverseWords(string s)
    {
        reverse(s.begin(), s.end());
        s.push_back(' ');
        int l;
        int r;
        int begin = 0;
        for (l = 0, r = 0; r < s.size(); r++)
        {
            if (s[r] != ' ')
                s[l++] = s[r];
            if (s[r] == ' ' && s[r + 1] != ' ' && s[0] != ' ')
            {
                s[l++] = ' ';
                reverse(s.begin() + begin, s.begin() + l - 1);
                begin = l;
            }
        }
        while (s[l - 1] == ' ')
            l--;
        s.resize(l);
        return s;
    }
};
// @lc code=end
