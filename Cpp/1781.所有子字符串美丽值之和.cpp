/*
 * @lc app=leetcode.cn id=1781 lang=cpp
 *
 * [1781] 所有子字符串美丽值之和
 */

// @lc code=start
class Solution
{
public:
    int beautySum(string s)
    {
        int n = s.size();
        int ret = 0;
        for (int i = 1; i < n; i++)
        {
            vector<int> fre(26, 0);
            for (int j = i; j >= 0; j--)
            {
                fre[s[j] - 'a']++;
                int max_fre = 0, min_fre = 10000;
                for (int k = 0; k < 26; k++)
                {
                    max_fre = max(max_fre, fre[k]);
                    if (fre[k] != 0)
                        min_fre = min(min_fre, fre[k]);
                }
                ret += max_fre - min_fre;
            }
        }
        return ret;
    }
};
// @lc code=end
