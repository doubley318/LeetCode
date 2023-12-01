/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> ans;
    vector<int> tmp;
    vector<vector<int>> combine(int n, int k)
    {
        small(n, k);
        return ans;
    }

    void small(int n, int k)
    {
        if (k == 0)
        {
            ans.push_back(tmp);
            return;
        }
        for (int i = n; i >= 1; i--)
        {
            tmp.push_back(i);
            small(i - 1, k - 1);
            tmp.pop_back();
        }
    }
};
// @lc code=end
