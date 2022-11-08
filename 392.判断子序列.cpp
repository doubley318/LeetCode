/*
 * @lc app=leetcode.cn id=392 lang=cpp
 *
 * [392] 判断子序列
 */

// @lc code=start
class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        int l = 0, r = 0;
        while (l < s.size() && r < t.size())
        {
            if (s[l] == t[r])
            {
                l++;
                r++;
            }
            else
            {
                r++;
            }
        }
        if (l == s.size())
            return true;
        else
            return false;
    }
};
// @lc code=end

