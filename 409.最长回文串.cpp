/*
 * @lc app=leetcode.cn id=409 lang=cpp
 *
 * [409] 最长回文串
 */

// @lc code=start
class Solution
{
public:
    int longestPalindrome(string s)
    {
        vector<int> tmp(70, 0);
        int ret = 0;
        for (char i : s)
            tmp[i - 'A']++;
        for (int i : tmp)
            ret += ret % 2 == 0 ? i : (i / 2 * 2);
        return ret;
    }
};
// @lc code=end
