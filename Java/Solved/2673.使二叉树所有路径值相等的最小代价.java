/*
 * @lc app=leetcode.cn id=2673 lang=java
 *
 * [2673] 使二叉树所有路径值相等的最小代价
 */

// @lc code=start
class Solution {
    int ret = 0;

    // 左子树和右子树一样大
    public int minIncrements(int n, int[] cost) {
        increment(0, cost);
        return ret;
    }

    // 检测每个根节点后面需要增加多少个
    private int increment(int root, int[] cost) {
        if ((root + 1) * 2 > cost.length) {
            return cost[root];
        }
        int l = increment((root + 1) * 2 - 1, cost);
        int r = increment((root + 1) * 2, cost);
        ret += Math.abs(r - l);
        return cost[root] + Math.max(r, l);
    }
}
// @lc code=end
