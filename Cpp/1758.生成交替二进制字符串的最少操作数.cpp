/*
 * @lc app=leetcode.cn id=1758 lang=cpp
 *
 * [1758] 生成交替二进制字符串的最少操作数
 */

// @lc code=start
class Solution
{
public:
    int minOperations(string s)
    {
        int n = s.length();
        int ans1 = 0, ans2 = 0;
        char pre1 = '0', pre2 = '1';
        for (int i = 0; i < n; i++)
        {
            if (s[i] == pre1)
                ans1++;
            if (s[i] == pre2)
                ans2++;
            swap(pre1, pre2);
        }
        return min(ans1, ans2);
    }
};
// @lc code=end
