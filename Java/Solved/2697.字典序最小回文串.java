/*
 * @lc app=leetcode.cn id=2697 lang=java
 *
 * [2697] 字典序最小回文串
 */

// @lc code=start
class Solution {
    public String makeSmallestPalindrome(String s) {
        char[] charS = s.toCharArray();
        int n = s.length();
        for (int i = 0; i < n / 2; i++) {
            if (charS[i] < charS[n - i - 1]) {
                charS[n - i - 1] = charS[i];
            } else {
                charS[i] = charS[n - i - 1];
            }
        }
        return new String(charS);
    }
}
// @lc code=end
