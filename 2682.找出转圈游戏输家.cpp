/*
 * @lc app=leetcode.cn id=2682 lang=cpp
 *
 * [2682] 找出转圈游戏输家
 */

// @lc code=start
class Solution
{
public:
    vector<int> circularGameLosers(int n, int k)
    {
        vector<int> num(n, 0);
        int p = 0, i = 1;
        while (num[p] == 0)
        {
            num[p] += 1;
            p = (p + i * k) % n;
            i++;
        }
        vector<int> res;
        for (int i = 0; i < num.size(); i++)
        {
            if (num[i] == 0)
                res.push_back(i + 1);
        }
        return res;
    }
};
// @lc code=end
