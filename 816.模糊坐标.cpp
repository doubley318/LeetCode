/*
 * @lc app=leetcode.cn id=816 lang=cpp
 *
 * [816] 模糊坐标
 */

// @lc code=start
class Solution
{
public:
    bool Z(string s)
    {
        if (s == to_string(stoi(s)))
            return true;
        else
            return false;
    }

    bool D(string s)
    {
        if (s.size() == 0 || s[s.size() - 1] != '0')
            return true;
        else
            return false;
    }

    vector<string> small(string s)
    {
        vector<string> ret;
        for (int i = 0; i < s.size(); i++)
        {
            string l = s.substr(0, i + 1);
            string r = s.substr(i + 1, s.size() - i - 1);
            if (Z(l) && D(r))
            {
                string z;
                if (r.size() == 0)
                    z = l;
                else
                    z = l + "." + r;
                ret.push_back(z);
            }
        }
        return ret;
    }

    vector<string> ambiguousCoordinates(string s)
    {
        vector<string> ret;
        for (int i = 1; i < s.size() - 2; i++)
        {
            vector<string> left = small(s.substr(1, i));
            vector<string> right = small(s.substr(i + 1, s.size() - 2 - i));
            if (left.size() != 0 && right.size() != 0)
            {
                for (int l = 0; l < left.size(); l++)
                {
                    for (int r = 0; r < right.size(); r++)
                    {
                        string tmp = "(" + left[l] + ", " + right[r] + ")";
                        ret.push_back(tmp);
                    }
                }
            }
        }
        return ret;
    }
};
// @lc code=end
