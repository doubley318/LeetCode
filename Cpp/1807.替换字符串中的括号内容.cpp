/*
 * @lc app=leetcode.cn id=1807 lang=cpp
 *
 * [1807] 替换字符串中的括号内容
 */

// @lc code=start
class Solution
{
public:
    string evaluate(string s, vector<vector<string>> &knowledge)
    {
        unordered_map<string, string> m;
        for (auto &kd : knowledge)
            m[kd[0]] = kd[1];
        bool addKey = false;
        string key, res;
        for (char c : s)
        {
            if (c == '(')
            {
                addKey = true;
            }
            else if (c == ')')
            {
                if (m.count(key) > 0)
                {
                    res += m[key];
                }
                else
                {
                    res.push_back('?');
                }
                addKey = false;
                key.clear();
            }
            else
            {
                if (addKey)
                {
                    key.push_back(c);
                }
                else
                {
                    res.push_back(c);
                }
            }
        }
        return res;
    }
};
// @lc code=end
