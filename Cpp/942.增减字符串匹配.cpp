/*
 * @lc app=leetcode.cn id=942 lang=cpp
 *
 * [942] 增减字符串匹配
 */

// @lc code=start
class Solution
{
public:
    vector<int> diStringMatch(string s)
    {
        vector<int> ans(s.length() + 1);
        int num_i = 0, num_d = s.length();
        for (int i = 0; i < s.length(); i++)
            if (s[i] == 'I')
                ans[i] = num_i++;
            else
                ans[i] = num_d--;
        ans[s.length()] = num_i;
        return ans;
    }
};
// @lc code=end
