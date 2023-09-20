/*
 * @lc app=leetcode.cn id=833 lang=cpp
 *
 * [833] 字符串中的查找与替换
 */

// @lc code=start
class Solution
{
public:
    string findReplaceString(string s, vector<int> &indices, vector<string> &sources, vector<string> &targets)
    {
        map<int, int> LL;
        for (int i = 0; i < indices.size(); i++)
        {
            bool y = true;
            for (int j = 0; j < sources[i].length(); j++)
            {
                if (sources[i][j] != s[indices[i] + j])
                {
                    y = false;
                    break;
                }
            }
            if (y)
            {
                LL.insert({indices[i], i});
            }
        }
        string res = "";
        int p = 0;
        for (pair<const int, int> &i : LL)
        {
            res = res + s.substr(p, indices[i.second] - p) + targets[i.second];
            p = indices[i.second] + sources[i.second].length();
        }
        res = res + s.substr(p);
        return res;
    }
};
// @lc code=end
