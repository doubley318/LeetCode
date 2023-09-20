/*
 * @lc app=leetcode.cn id=394 lang=cpp
 *
 * [394] 字符串解码
 */

// @lc code=start
class Solution {
public:
    string getString(string& s, int& ptr)
    {
        int n = s.size();
        int l = ptr;
        while (ptr < n && s[ptr] <= 'z' && s[ptr] >= 'a') {
            ptr++;
        }
        return s.substr(l, ptr - l);
    }

    string getDigits(string& s, int& ptr)
    {
        int n = s.size();
        int l = ptr;
        while (ptr < n && s[ptr] <= '9' && s[ptr] >= '0') {
            ptr++;
        }
        return s.substr(l, ptr - l);
    }

    string decodeString(string s)
    {
        int n = s.length();
        int l = 0;
        stack<string> str;
        while (l < n) {
            string tmp_s = "";
            tmp_s = getDigits(s, l);
            if (tmp_s.length() != 0) {
                str.push(tmp_s);
            }
            if (l < n && s[l] == '[') {
                str.push("[");
                l++;
            }
            tmp_s = getString(s, l);
            if (tmp_s.length() != 0) {
                if (!str.empty()) {
                    string tmppp_s = str.top();
                    if (tmppp_s[0] >= 'a' && tmppp_s[0] <= 'z') {
                        str.pop();
                        tmp_s = tmppp_s + tmp_s;
                    }
                }
                str.push(tmp_s);
            }
            if (l < n && s[l] == ']') {
                l++;
                tmp_s = str.top();
                str.pop();
                str.pop();
                int times = stoi(str.top());
                str.pop();
                string topush_s = "";
                while (times > 0) {
                    topush_s += tmp_s;
                    times--;
                }
                if (!str.empty() && str.top() != "[") {
                    tmp_s = str.top();
                    topush_s = tmp_s + topush_s;
                    str.pop();
                }
                str.push(topush_s);
            }
        }
        if (str.empty())
            return "";
        string res = str.top();
        str.pop();
        if (!str.empty()) {
            res = str.top() + res;
        }
        return res;
    }
};
// @lc code=end
