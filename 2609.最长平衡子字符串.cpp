/*
 * @lc app=leetcode.cn id=2609 lang=cpp
 *
 * [2609] 最长平衡子字符串
 */

// @lc code=start
class Solution {
public:
    int findTheLongestBalancedSubstring(string s)
    {
        int n = s.length();
        int ret = 0;
        for (int i = 0; i < n;) {
            int len0 = 0, len1 = 0;
            for (; i < n && s[i] == '0'; i++) {
                len0++;
            }
            for (; i < n && s[i] == '1'; i++) {
                len1++;
            }
            ret = max(ret, 2 * min(len0, len1));
        }
        return ret;
    }
};
// @lc code=end
