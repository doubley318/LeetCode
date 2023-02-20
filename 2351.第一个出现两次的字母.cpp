/*
 * @lc app=leetcode.cn id=2351 lang=cpp
 *
 * [2351] 第一个出现两次的字母
 */

// @lc code=start
class Solution
{
public:
    char repeatedCharacter(string s)
    {
        int x = 0, t;
        for (int i = 0; i < s.size(); i++)
        {
            t = x;
            x = (x | (1 << (s[i] - 'a')));
            if (t == x)
                return s[i];
        }
        return '0';
    }
};
// @lc code=end
