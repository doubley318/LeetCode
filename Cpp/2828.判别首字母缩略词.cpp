/*
 * @lc app=leetcode.cn id=2828 lang=cpp
 *
 * [2828] 判别首字母缩略词
 */

// @lc code=start
class Solution {
public:
    bool isAcronym(vector<string>& words, string s)
    {
        if (s.length() != words.size()) {
            return false;
        }
        for (int i = 0; i < words.size(); i++) {
            if (words[i][0] != s[i]) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
