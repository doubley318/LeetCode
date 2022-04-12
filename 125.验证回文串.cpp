/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 */

// @lc code=start
class Solution
{
public:
    bool isPalindrome(string s)
    {
        int l = 0, r = s.length() - 1;
        while (l <= r)
        {
            if (isalnum(s[l]) && isalnum(s[r]))
            {
                if (tolower(s[l]) != tolower(s[r]))
                    return false;
            }
            else if (isalnum(s[l]))
            {
                r--;
                continue;
            }
            else if (isalnum(s[r]))
            {
                l++;
                continue;
            }
            l++;
            r--;
        }
        return true;
    }
};
// @lc code=end
