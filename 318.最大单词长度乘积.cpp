/*
 * @lc app=leetcode.cn id=318 lang=cpp
 *
 * [318] 最大单词长度乘积
 */

// @lc code=start
class Solution
{
public:
    int word2int(string words)
    {
        int ret = 0;
        for (int i = 0; i < words.size(); i++)
        {
            int tmp = 1;
            tmp = tmp << (words[i] - 'a');
            ret = ret | tmp;
        }
        return ret;
    }

    int maxProduct(vector<string> &words)
    {
        int ret = 0;
        vector<int> w(words.size(), 0);
        w[0] = word2int(words[0]);
        for (int i = 1; i < words.size(); i++)
        {
            w[i] = word2int(words[i]);
            for (int j = i - 1; j >= 0; j--)
            {
                if ((w[i] & w[j]) == 0)
                    ret = max(ret, (int)(words[i].size() * words[j].size()));
            }
        }
        return ret;
    }
};
// @lc code=end
