/*
 * @lc app=leetcode.cn id=889 lang=java
 *
 * [889] 根据前序和后序遍历构造二叉树
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
    public TreeNode constructFromPrePost(int[] preorder, int[] postorder) {
        return buildLeftRight(preorder, postorder, 0, preorder.length - 1, 0, postorder.length - 1);
    }

    public TreeNode buildLeftRight(int[] preorder, int[] postorder, int preL, int preR, int postL, int postR) {
        if (preL > preR) {
            return null;
        }
        TreeNode root = new TreeNode(preorder[preL]);
        if (preL == preR) {
            return root;
        }
        int nextRoot = preorder[preL + 1];
        int m = 0;
        for (; m < postR - postL; m++) {
            if (postorder[postL + m] == nextRoot) {
                break;
            }
        }
        root.left = buildLeftRight(preorder, postorder, preL + 1, preL + m + 1, postL, postL + m);
        root.right = buildLeftRight(preorder, postorder, preL + m + 2, preR, postL + m + 1, postR - 1);
        return root;
    }
}
// @lc code=end
