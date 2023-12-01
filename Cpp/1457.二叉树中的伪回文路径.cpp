/*
 * @lc app=leetcode.cn id=1457 lang=cpp
 *
 * [1457] 二叉树中的伪回文路径
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ret = 0;

    bool check(const vector<int>& nums)
    {
        int oddNums = 0;
        for (const int& i : nums) {
            if (i & 1 == 1) {
                oddNums++;
            }
        }
        if (oddNums > 1) {
            return false;
        }
        return true;
    }

    void dfs(TreeNode* root, vector<int>& nums)
    {
        nums[root->val]++;
        if (root->left == nullptr && root->right == nullptr) {
            if (check(nums)) {
                ret++;
            }
        } else {
            if (root->left != nullptr) {
                dfs(root->left, nums);
            }
            if (root->right != nullptr) {
                dfs(root->right, nums);
            }
        }
        nums[root->val]--;
    }

    int pseudoPalindromicPaths(TreeNode* root)
    {
        ret = 0;
        vector<int> nums(10, 0);
        dfs(root, nums);
        return ret;
    }
};
// @lc code=end
