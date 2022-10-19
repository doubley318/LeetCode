/*
 * @lc app=leetcode.cn id=187 lang=cpp
 *
 * [187] 重复的DNA序列
 */

// @lc code=start
class Solution
{
public:
    const int L = 10;
    unordered_map<char, int> bin = {{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};

    vector<string> findRepeatedDnaSequences(string s)
    {
        unordered_map<int, int> cnt;
        vector<string> ret;
        if (s.size() <= 10)
            return ret;
        int x = 0;
        for (int i = 0; i < 9; i++)
        {
            x = (x << 2) | bin[s[i]];
        }
        for (int i = 9; i < s.size(); i++)
        {
            x = ((x << 2) | bin[s[i]]) & ((1 << 20) - 1);
            if (++cnt[x] == 2)
                ret.push_back(s.substr(i - 9, 10));
        }
        return ret;
    }
};
// @lc code=end
