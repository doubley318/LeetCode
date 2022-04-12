/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 */

// @lc code=start
class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        if (needle.size() == 0)
            return 0;
        vector<int> next(needle.size());
        next[0] = -1;
        int j = 0;
        int i = 1;
        while (i < needle.size() - 1)
        {
            if (needle[i] == needle[j])
            {
                next[i + 1] = j + 1;
                i++;
                j++;
            }
            else
            {
                if (j == 0)
                {
                    next[i + 1] = 0;
                    i++;
                }
                else
                    j = next[j];
            }
        }
        i = 0;
        j = 0;
        while (i < haystack.size())
        {
            if (haystack[i] == needle[j])
            {
                j++;
                i++;
            }
            else
            {
                if (j != 0)
                    j = next[j];
                else
                    i++;
            }
            if (j == needle.size())
                return i - j;
        }
        return -1;
    }
};
// @lc code=end
