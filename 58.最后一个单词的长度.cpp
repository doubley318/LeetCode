/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 */

// @lc code=start
class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        if (s.length() == 1)
            if (s[0] != ' ')
                return 1;
        int l = 0, r = 0;
        int ans = 0;
        for (; r < s.size(); r++)
        {
            if (s[r] == ' ')
            {
                if (s[l] != ' ')
                    ans = r - l;
                else
                {
                    if (r - l > 1)
                        ans = r - l - 1;
                }
                l = r;
            }
        }
        if (l == 0 && s[0] != ' ')
            return r - l;
        if (r - l > 1)
            return r - l - 1;
        return ans;
    }
};
// @lc code=end
