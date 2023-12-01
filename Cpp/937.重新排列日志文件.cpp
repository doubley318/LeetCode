/*
 * @lc app=leetcode.cn id=937 lang=cpp
 *
 * [937] 重新排列日志文件
 */

// @lc code=start
class Solution
{
public:
    static bool mycomp(string s1, string s2)
    {
        int t1 = s1.find_first_of(" ");
        int t2 = s2.find_first_of(" ");
        if (s1.substr(t1) != s2.substr(t2))
            return s1.substr(t1) < s2.substr(t2);
        return s1.substr(0, t1) < s2.substr(0, t2);
    }

    vector<string> reorderLogFiles(vector<string> &logs)
    {
        int r = logs.size() - 1;
        int count = 0;
        for (int i = logs.size() - 2; i >= 0; i--)
        {
            if (isdigit(logs[r][logs[r].length() - 1]))
                r--, count++;
            else if (isdigit(logs[i][logs[i].length() - 1]))
            {
                string s = logs[i];
                logs[i] = logs[r];
                logs[r] = s;
                r--;
                count++;
            }
        }
        stable_sort(logs.begin(), logs.begin() + logs.size() - count, mycomp);
        return logs;
    }
};
// @lc code=end
