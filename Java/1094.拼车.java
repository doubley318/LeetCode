/*
 * @lc app=leetcode.cn id=1094 lang=java
 *
 * [1094] 拼车
 */

// @lc code=start
class Solution {
    public boolean carPooling(int[][] trips, int capacity) {
        int[] cars = new int[1005];
        for (int i = 0; i < trips.length; i++) {
            cars[trips[i][1] + 1] += trips[i][0];
            cars[trips[i][2] + 1] -= trips[i][0];
        }
        for (int i = 1; i < 1005; i++) {
            cars[i] += cars[i - 1];
            if (cars[i] > capacity) {
                return false;
            }
        }
        return true;
    }
}
// @lc code=end
