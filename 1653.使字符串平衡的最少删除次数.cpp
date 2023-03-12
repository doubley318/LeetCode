/*
 * @lc app=leetcode.cn id=1653 lang=cpp
 *
 * [1653] 使字符串平衡的最少删除次数
 */

// @lc code=start
class Solution
{
public:
    int minimumDeletions(string s)
    {
        int n = s.size();
        int res = 100005;
        vector<int> a(n + 1, 0);
        vector<int> b(n + 1, 0);
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'b')
                a[i + 1] = a[i] + 1;
            else
                a[i + 1] = a[i];
            if (s[n - i - 1] == 'a')
                b[n - i - 1] = b[n - i] + 1;
            else
                b[n - i - 1] = b[n - i];
        }
        for (int i = 0; i < n; i++)
        {
            res = min(res, a[i + 1] + b[i]);
        }
        return res - 1;
    }
};
// @lc code=end
