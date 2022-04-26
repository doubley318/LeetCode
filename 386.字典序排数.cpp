/*
 * @lc app=leetcode.cn id=386 lang=cpp
 *
 * [386] 字典序排数
 */

// @lc code=start
class Solution
{
public:
    vector<int> lexicalOrder(int n)
    {
        vector<int> ans(n);
        ans[0] = 1;
        for (int i = 1; i < n; i++)
        {
            ans[i] = ans[i - 1] * 10;
            if (ans[i] > n)
            {
                while (ans[i] >= n || ans[i] % 10 == 9)
                    ans[i] = ans[i] / 10;
                ans[i]++;
            }
        }
        return ans;
    }
};
// @lc code=end
