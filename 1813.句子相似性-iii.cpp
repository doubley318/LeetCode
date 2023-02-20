/*
 * @lc app=leetcode.cn id=1813 lang=cpp
 *
 * [1813] 句子相似性 III
 */

// @lc code=start
class Solution
{
public:
    vector<string> subsentence(string s)
    {
        vector<string> res;
        for (auto i = s.find_first_of(' '); i != string::npos; i = s.find_first_of(' '))
        {
            res.push_back(s.substr(0, i));
            s = s.substr(i + 1);
        }
        res.push_back(s);
        return res;
    }
    bool areSentencesSimilar(string sentence1, string sentence2)
    {
        vector<string> s1 = subsentence(sentence1);
        vector<string> s2 = subsentence(sentence2);
        int l1 = 0, l2 = 0;
        while (l1 < s1.size() && l1 < s2.size() && s1[l1] == s2[l1])
        {
            l1++;
        }
        while (l2 < s1.size() - l1 && l2 < s2.size() - l1 && s1[s1.size() - 1 - l2] == s2[s2.size() - 1 - l2])
        {
            l2++;
        }
        if (l1 + l2 == s1.size() || l1 + l2 == s2.size())
            return true;
        else
            return false;
    }
};
// @lc code=end
