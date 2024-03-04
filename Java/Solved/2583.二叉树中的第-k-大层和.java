/*
 * @lc app=leetcode.cn id=2583 lang=java
 *
 * [2583] 二叉树中的第 K 大层和
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 * int val;
 * TreeNode left;
 * TreeNode right;
 * TreeNode() {}
 * TreeNode(int val) { this.val = val; }
 * TreeNode(int val, TreeNode left, TreeNode right) {
 * this.val = val;
 * this.left = left;
 * this.right = right;
 * }
 * }
 */
class Solution {
    public long kthLargestLevelSum(TreeNode root, int k) {
        PriorityQueue<Long> pq = new PriorityQueue<Long>(k, new Comparator<Long>() {
            public int compare(Long o1, Long o2) {
                if (o1 - o2 > 0)
                    return 1;
                else if (o1 == o2)
                    return 0;
                return -1;
            }
        });
        Queue<TreeNode> que = new LinkedList<>();
        if (root == null) {
            return -1;
        }
        que.add(root);
        while (!que.isEmpty()) {
            int count = que.size();
            Long sum = 0l;
            for (int i = 0; i < count; i++) {
                TreeNode tmp = que.poll();
                if (tmp.left != null) {
                    que.add(tmp.left);
                }
                if (tmp.right != null) {
                    que.add(tmp.right);
                }
                sum += tmp.val;
            }
            pq.add(sum);
            if (pq.size() > k) {
                pq.poll();
            }
        }
        if (pq.size() < k) {
            return -1;
        }
        return pq.poll();
    }
}
// @lc code=end
