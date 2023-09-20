/*
 * @lc app=leetcode.cn id=2423 lang=cpp
 *
 * [2423] 删除字符使频率相同
 */

// @lc code=start
class Solution
{
public:
    bool equalFrequency(string word)
    {
        vector<int> tmp(26, 0);
        for (char &i : word)
        {
            tmp[i - 'a']++;
        }
        int tmp_max = 0;
        for (int &i : tmp)
        {
            tmp_max = max(i, tmp_max);
        }
        if (tmp_max == 1)
            return true;
        int res = 0;
        for (int &i : tmp)
        {
            if (i == tmp_max)
            {
                i--;
                res++;
            }
        }
        if (res > 1)
            return false;
        tmp_max -= 1;
        for (int &i : tmp)
        {
            if (i != 0 && i != tmp_max)
                return false;
        }
        return true;
    }
};
// @lc code=end
