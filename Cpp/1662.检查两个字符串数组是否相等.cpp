/*
 * @lc app=leetcode.cn id=1662 lang=cpp
 *
 * [1662] 检查两个字符串数组是否相等
 */

// @lc code=start
class Solution
{
public:
    bool arrayStringsAreEqual(vector<string> &word1, vector<string> &word2)
    {
        int l1 = 0, l2 = 0;
        int i1 = 0, i2 = 0;
        while (l1 < word1.size() && l2 < word2.size())
        {
            if (word1[l1][i1] != word2[l2][i2])
                return false;
            i1++;
            i2++;
            if (i1 == word1[l1].size())
            {
                i1 = 0;
                l1++;
            }
            if (i2 == word2[l2].size())
            {
                i2 = 0;
                l2++;
            }
        }
        if (l1 == word1.size() && l2 == word2.size())
            return true;
        return false;
    }
};
// @lc code=end
