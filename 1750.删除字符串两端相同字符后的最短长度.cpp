/*
 * @lc app=leetcode.cn id=1750 lang=cpp
 *
 * [1750] 删除字符串两端相同字符后的最短长度
 */

// @lc code=start
class Solution
{
public:
    int minimumLength(string s)
    {
        int l = 0, r = s.size() - 1;
        while (l <= r)
        {
            if (s[l] == s[r])
            {
                int L = l, R = r;
                char t = s[l];
                while (l <= r && t == s[l])
                {
                    l++;
                }
                while (l <= r && t == s[r])
                {
                    r--;
                }
                if (l > r && R == L)
                    return 1;
            }
            else
                break;
        }
        return r - l + 1;
    }
};
// @lc code=end
