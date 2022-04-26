/*
 * @lc app=leetcode.cn id=868 lang=cpp
 *
 * [868] 二进制间距
 */

// @lc code=start
class Solution
{
public:
    int binaryGap(int n)
    {
        int ans = 0, l = 0, r = 1;
        while (n > 0 && n % 2 == 0)
            r++, n = n >> 1;
        n = n >> 1;
        l = r + 1;
        while (n > 0)
        {
            if (n % 2 == 1)
                ans = max(ans, l - r), r = l;
            l++;
            n >>= 1;
        }
        return ans;
    }
};
// @lc code=end
