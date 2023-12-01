/*
 * @lc app=leetcode.cn id=796 lang=cpp
 *
 * [796] 旋转字符串
 */

// @lc code=start
class Solution
{
public:
    bool rotateString(string s, string goal)
    {
        if (s.size() != goal.size())
            return false;
        int t = 0;
        if (s == goal)
            return true;
        while (t < s.size() - 1)
        {
            s = s.substr(1, s.size()) + s.substr(0, 1);
            if (s == goal)
                return true;
            t++;
        }
        return false;
    }
};
// @lc code=end
