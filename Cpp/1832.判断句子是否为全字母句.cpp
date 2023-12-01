/*
 * @lc app=leetcode.cn id=1832 lang=cpp
 *
 * [1832] 判断句子是否为全字母句
 */

// @lc code=start
class Solution
{
public:
    bool checkIfPangram(string sentence)
    {
        int t = 0, n = sentence.size(), x = (1 << 26) - 1;
        for (int i = 0; i < n; i++)
        {
            t = t | (1 << (sentence[i] - 'a'));
            if (t == x)
                return true;
        }
        return false;
    }
};
// @lc code=end
