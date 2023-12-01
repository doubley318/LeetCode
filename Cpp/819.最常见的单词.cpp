/*
 * @lc app=leetcode.cn id=819 lang=cpp
 *
 * [819] 最常见的单词
 */

// @lc code=start
class Solution {
public:
    string mostCommonWord(string paragraph, vector<string> &banned)
    {
        map<string, int> tmp;
        int maxnum = 0;
        string t;
        set<string> ban;
        for (string i : banned)
            ban.insert(i);
        for (int i = 0; i <= paragraph.length(); i++)
        {
            if (i < paragraph.length() && isalpha(paragraph[i]))
                t = t + (char)tolower(paragraph[i]);
            else
            {
                if (t.length() != 0)
                {
                    if (ban.find(t) == ban.end())
                    {
                        if (tmp.find(t) == tmp.end())
                            tmp.insert(pair<string, int>{t, 1}), maxnum = max(maxnum, 1);
                        else
                            tmp.find(t)->second++, maxnum = max(tmp.find(t)->second, maxnum);
                    }
                    t = "";
                }
            }
        }
        for (auto i : tmp)
        {
            if (i.second == maxnum)
                return i.first;
        }
        return t;
    }
};
// @lc code=end

