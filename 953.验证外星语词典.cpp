/*
 * @lc app=leetcode.cn id=953 lang=cpp
 *
 * [953] 验证外星语词典
 */

// @lc code=start
class Solution {
public:
    string myorder;
    bool isAlienSorted(vector<string> &words, string order)
    {
        myorder = order;
        for (int i = 1; i < words.size(); i++)
            if (!small(words[i - 1], words[i]))
                return false;
        return true;
    }

    bool small(string a, string b)
    {
        int i = 0;
        while (i < a.length() && i < b.length())
        {
            int ai = location(a[i]);
            int bi = location(b[i]);
            if (ai > bi)
                return false;
            if (ai < bi)
                return true;
            i++;
        }
        if (i < a.length())
            return false;
        return true;
    }

    int location(char c)
    {
        for (int i = 0; i < 26; i++)
            if (c == myorder[i])
                return i;
        return -1;
    }
};
// @lc code=end

