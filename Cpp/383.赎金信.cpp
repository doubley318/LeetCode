/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信
 */

// @lc code=start
class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        vector<int> ma(26, 0);
        for (char c : magazine)
        {
            ma[c - 'a']++;
        }
        for (char c : ransomNote)
        {
            ma[c - 'a']--;
        }
        for (int i = 0; i < 26; i++)
        {
            if (ma[i] < 0)
                return false;
        }
        return true;
    }
};
// @lc code=end
