/*
 * @lc app=leetcode.cn id=1410 lang=cpp
 *
 * [1410] HTML 实体解析器
 */

// @lc code=start
class Solution {
public:
    string entityParser(string text)
    {
        unordered_map<string, char> m;
        m["quot;"] = '"';
        m["apos;"] = '\'';
        m["amp;"] = '&';
        m["gt;"] = '>';
        m["lt;"] = '<';
        m["frasl;"] = '/';
        string ret = "";
        int n = text.size();
        for (int i = 0; i < n; i++) {
            if (text[i] == '&') {
                string tmp = "";
                if (n - i - 1 >= 6 && m.find(text.substr(i + 1, 6)) != m.end()) {
                    tmp = text.substr(i + 1, 6);
                } else if (n - i - 1 >= 5 && m.find(text.substr(i + 1, 5)) != m.end()) {
                    tmp = text.substr(i + 1, 5);
                } else if (n - i - 1 >= 4 && m.find(text.substr(i + 1, 4)) != m.end()) {
                    tmp = text.substr(i + 1, 4);
                } else if (n - i - 1 >= 3 && m.find(text.substr(i + 1, 3)) != m.end()) {
                    tmp = text.substr(i + 1, 3);
                }
                if (tmp.length() != 0) {
                    ret.push_back(m[tmp]);
                    i = i + tmp.length();
                    continue;
                }
            }
            ret.push_back(text[i]);
        }
        return ret;
    }
};
// @lc code=end
