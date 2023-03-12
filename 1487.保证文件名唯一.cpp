/*
 * @lc app=leetcode.cn id=1487 lang=cpp
 *
 * [1487] 保证文件名唯一
 */

// @lc code=start
class Solution
{
public:
    vector<string> getFolderNames(vector<string> &names)
    {
        map<string, int> m;
        for (int i = 0; i < names.size(); i++)
        {
            map<string, int>::iterator tmp = m.find(names[i]);
            if (tmp != m.end())
            {
                map<string, int>::iterator t = tmp;
                string tt;
                while (t != m.end())
                {
                    tmp->second = tmp->second + 1;
                    tt = names[i] + "(" + to_string(tmp->second) + ")";
                    t = m.find(tt);
                }
                names[i] = tt;
            }
            m.insert({names[i], 0});
        }
        return names;
    }
};
// @lc code=end
