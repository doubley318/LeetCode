/*
 * @lc app=leetcode.cn id=2287 lang=cpp
 *
 * [2287] 重排字符形成目标字符串
 */

// @lc code=start
class Solution
{
public:
    int rearrangeCharacters(string s, string target)
    {
        vector<int> times(26, 0);
        for (char i : target)
            times[i - 'a']++;
        vector<int> time(26, 0);
        for (char i : s)
            time[i - 'a']++;
        int ret = INT_MAX;
        for (int i = 0; i < 26; i++)
            if (times[i] != 0)
                ret = min(time[i] / times[i], ret);
        return ret;
    }
};
// @lc code=end
