/*
 * @lc app=leetcode.cn id=844 lang=cpp
 *
 * [844] 比较含退格的字符串
 */

// @lc code=start
class Solution
{
public:
    bool backspaceCompare(string s, string t)
    {
        int shat = 0, shas = 0;
        int l = s.size() - 1, r = t.size() - 1;
        while (l >= 0 || r >= 0)
        {
            while (l >= 0)
            {
                if (s[l] == '#')
                {
                    shas++;
                    l--;
                }
                else if (shas > 0)
                {
                    l--;
                    shas--;
                }
                else
                    break;
            }

            while (r >= 0)
            {
                if (t[r] == '#')
                {
                    shat++;
                    r--;
                }
                else if (shat > 0)
                {
                    r--;
                    shat--;
                }
                else
                    break;
            }
            if (l >= 0 && r >= 0)
            {
                if (s[l] != t[r])
                {
                    return false;
                }
            }
            else
            {
                if (l >= 0 || r >= 0)
                {
                    return false;
                }
            }
            l--, r--;
        }
        return true;
    }
};
// @lc code=end
