/*
 * @lc app=leetcode.cn id=2454 lang=java
 *
 * [2454] 下一个更大元素 IV
 */

// @lc code=start
class Solution {
    public int[] secondGreaterElement(int[] nums) {
        int n = nums.length;
        int[] ret = new int[n];
        for (int i = 0; i < n; i++) {
            int big = 0, j = i + 1;
            while (j < n && big < 2) {
                if (nums[j] > nums[i]) {
                    big++;
                }
                j++;
            }
            if (big == 2) {
                ret[i] = nums[j - 1];
            } else {
                ret[i] = -1;
            }
        }
        return ret;
    }
}
// @lc code=end
