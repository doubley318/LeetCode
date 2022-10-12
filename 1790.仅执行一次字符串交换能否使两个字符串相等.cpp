/*
 * @lc app=leetcode.cn id=1790 lang=cpp
 *
 * [1790] 仅执行一次字符串交换能否使两个字符串相等
 */

// @lc code=start
class Solution
{
public:
    bool areAlmostEqual(string s1, string s2)
    {
        if (s1.size() != s2.size())
            return false;
        vector<int> diff_location;
        for (int i = 0; i < s1.size() && diff_location.size() < 3; i++)
            if (s1[i] != s2[i])
                diff_location.push_back(i);
        if (diff_location.size() % 2 == 1)
            return false;
        if (diff_location.size() == 0)
            return true;
        if (s1[diff_location[0]] == s2[diff_location[1]] && s1[diff_location[1]] == s2[diff_location[0]])
            return true;
        return false;
    }
};
// @lc code=end
