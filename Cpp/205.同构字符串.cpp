/*
 * @lc app=leetcode.cn id=205 lang=cpp
 *
 * [205] 同构字符串
 */

// @lc code=start
class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        vector<int> maps_t(128, -1);
        vector<int> mapt_s(128, -1);
        for (int tmp = 0; tmp < s.length(); tmp++)
        {
            if (maps_t[s[tmp]] == -1 && mapt_s[t[tmp]] == -1)
                maps_t[s[tmp]] = t[tmp], mapt_s[t[tmp]] = s[tmp];
            else if (maps_t[s[tmp]] != t[tmp])
                return false;
        }
        return true;
    }
};
// @lc code=end
