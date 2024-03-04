/*
 * @lc app=leetcode.cn id=106 lang=java
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
    public TreeNode buildTree(int[] inorder, int[] postorder) {
        return buildLeftRight(inorder, postorder, 0, inorder.length - 1, 0, postorder.length - 1);
    }

    public TreeNode buildLeftRight(int[] inorder, int[] postorder, int il, int ir, int pl, int pr) {
        if (il > ir) {
            return null;
        }
        TreeNode root = new TreeNode(postorder[pr]);
        int m = il;
        for (; m <= ir; m++) {
            if (inorder[m] == postorder[pr]) {
                break;
            }
        }
        root.left = buildLeftRight(inorder, postorder, il, m - 1, pl, pl + m - il - 1);
        root.right = buildLeftRight(inorder, postorder, m + 1, ir, pl + m - il, pr - 1);
        return root;
    }
}
// @lc code=end
