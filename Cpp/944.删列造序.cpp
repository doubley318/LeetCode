/*
 * @lc app=leetcode.cn id=944 lang=cpp
 *
 * [944] 删列造序
 */

// @lc code=start
class Solution
{
public:
    int minDeletionSize(vector<string> &strs)
    {
        int ans = 0;
        for (int i = 0; i < strs[0].size(); i++)
        {
            char tmp = strs[0][i];
            for (int j = 1; j < strs.size(); j++)
            {
                if (tmp > strs[j][i])
                {
                    ans++;
                    break;
                }
                tmp = strs[j][i];
            }
        }
        return ans;
    }
};
// @lc code=end
