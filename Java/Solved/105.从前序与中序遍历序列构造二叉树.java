/*
 * @lc app=leetcode.cn id=105 lang=java
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        return buildLeftRight(preorder, inorder, 0, preorder.length - 1, 0, inorder.length - 1);
    }

    public TreeNode buildLeftRight(int[] preorder, int[] inorder, int pl, int pr, int il, int ir) {
        if (pl > pr) {
            return null;
        }
        TreeNode root = new TreeNode(preorder[pl]);
        int m = il;
        for (; m <= ir; m++) {
            if (inorder[m] == preorder[pl]) {
                break;
            }
        }
        root.left = buildLeftRight(preorder, inorder, pl + 1, pl + m - il, il, m - 1);
        root.right = buildLeftRight(preorder, inorder, pl + m - il + 1, pr, m + 1, ir);
        return root;
    }
}
// @lc code=end
