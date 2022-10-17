/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> ret;
    void small(int k, int n, int t, vector<int> tmp)
    {
        if (n < 0 || k < 0)
            return;
        if (n == 0 && k == 0)
        {
            ret.push_back(tmp);
            return;
        }
        vector<int> mark = tmp;
        while (t < 10)
        {
            mark.push_back(t);
            small(k - 1, n - t, t + 1, mark);
            mark.pop_back();
            t++;
        }
    }

    vector<vector<int>> combinationSum3(int k, int n)
    {
        if ((k * k + k) / 2 > n || (k * 19 - k * k) / 2 < n)
            return ret;
        vector<int> tmp;
        small(k, n, 1, tmp);
        return ret;
    }
};
// @lc code=end
