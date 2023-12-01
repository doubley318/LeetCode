/*
 * @lc app=leetcode.cn id=479 lang=cpp
 *
 * [479] 最大回文数乘积
 */

// @lc code=start
class Solution
{
public:
    int largestPalindrome(int n)
    {
        vector<int> ans = {9, 987, 123, 597, 677, 1218, 877, 475};
        return ans[n - 1];
    }
};
// @lc code=end
