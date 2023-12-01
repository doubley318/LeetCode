/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

// @lc code=start
class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.size() == 1)
            return strs[0];
        string res;
        for (int i = 0; i < strs[0].size(); i++)
        {
            int tmp = 0;
            for (int j = 1; j < strs.size(); j++)
            {
                if (strs[j][i] == strs[0][i])
                    tmp = 1;
                else
                {
                    tmp = 0;
                    break;
                }
            }
            if (tmp == 0)
                return res;
            else
                res += strs[0][i];
        }
        return res;
    }
};
// @lc code=end
