/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */

// @lc code=start
class Solution {
public:
    bool ishuiwen(string s)
    {
        int l = 0, r = s.size() - 1;
        while (l < r)
        {
            if (s[l] != s[r])
                return false;
            l++, r--;
        }
        return true;
    }

    void insertpath(string s, vector<vector<string>> &res, vector<string> path)
    {
        if (s.size() == 0)
        {
            res.push_back(path);
            return;
        }
        for (int i = 1; i <= s.size(); i++)
        {
            string tmp = s.substr(0, i);
            if (ishuiwen(tmp))
            {
                path.push_back(tmp);
                insertpath(s.substr(i), res, path);
                path.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> res;
        vector<string> path;
        insertpath(s, res, path);
        return res;
    }
};
// @lc code=end

