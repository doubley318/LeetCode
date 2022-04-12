/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
class Solution {
public:
    vector<string> letterCombinations(string digits)
    {

        vector<string> res;
        if (digits.length() == 0)
            return res;
        map<char, string> m = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
        string s="";
        con(res,m,digits,0,s);
        return res;
    }

    void con(vector<string> &res, map<char, string> mp, string di, int l, string s)
    {
        if (l == di.length())
            res.push_back(s);
        else
        {
            string t;
            for (int i = 0; i < mp.find(di[l])->second.length(); i++)
            {
                t = s + mp.find(di[l])->second[i];
                con(res, mp, di, l+1, t);
            }
        }
    }
};
// @lc code=end

