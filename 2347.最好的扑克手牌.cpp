/*
 * @lc app=leetcode.cn id=2347 lang=cpp
 *
 * [2347] 最好的扑克手牌
 */

// @lc code=start
class Solution
{
public:
    string bestHand(vector<int> &ranks, vector<char> &suits)
    {
        char first = suits[0];
        int t = 1;
        for (; t < 5; t++)
            if (first != suits[t])
                break;
        if (t == 5)
            return "Flush";
        vector<int> pai(13, 0);
        for (int i = 0; i < 5; i++)
        {
            pai[ranks[i] - 1]++;
        }
        bool pair = false;
        bool kind = false;
        for (int i = 0; i < 13; i++)
        {
            if (pai[i] >= 3)
                kind = true;
            else if (pai[i] == 2)
                pair = true;
        }
        if (kind)
            return "Three of a Kind";
        if (pair)
            return "Pair";
        return "High Card";
    }
};
// @lc code=end
