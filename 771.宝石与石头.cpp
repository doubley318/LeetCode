/*
 * @lc app=leetcode.cn id=771 lang=cpp
 *
 * [771] 宝石与石头
 */

// @lc code=start
class Solution
{
public:
    inline int find_seq(char c)
    {
        return (c % 32 - 1) + (c / 96) * 26;
    }

    int numJewelsInStones(string jewels, string stones)
    {
        vector<bool> The_Jewels(52, false);
        for (char &c : jewels)
        {
            The_Jewels[find_seq(c)] = true;
        }
        int ret = 0;
        for (char &c : stones)
        {
            if (The_Jewels[find_seq(c)])
                ret++;
        }
        return ret;
    }
};
// @lc code=end
