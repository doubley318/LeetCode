/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start
class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> p_num;
        p_num = vector<int>(26, 0);
        vector<int> ret;
        for (int i = 0; i < p.size(); i++)
            p_num[p[i] - 'a']++;
        int l = 0, r = 0;
        while (r < s.size())
        {
            p_num[s[r] - 'a']--;
            while (p_num[s[r] - 'a'] < 0)
            {
                p_num[s[l] - 'a']++;
                l++;
            }
            if (r - l + 1 == p.size())
                ret.push_back(l);
            r++;
        }
        return ret;
    }
};
// @lc code=end
