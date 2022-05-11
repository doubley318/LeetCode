/*
 * @lc app=leetcode.cn id=449 lang=cpp
 *
 * [449] 序列化和反序列化二叉搜索树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    void xianxu(TreeNode *root, string &s)
    {
        if (!root)
            return;
        s = s + to_string(root->val) + ",";
        xianxu(root->left, s);
        xianxu(root->right, s);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        string ret;
        xianxu(root, ret);
        return ret;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        vector<int> data_array;
        while (data.size() > 1)
        {
            data_array.push_back(stoi(data.substr(0, data.find_first_of(','))));
            data = data.substr(data.find_first_of(',') + 1);
        }
        return small(data_array, 0, data_array.size() - 1);
    }

    TreeNode *small(vector<int> data_array, int pre_l, int pre_r)
    {
        if (pre_l > pre_r)
            return nullptr;
        int root_val = data_array[pre_l], in_m = pre_l + 1;
        TreeNode *root = new TreeNode(root_val);
        for (; in_m <= pre_r; in_m++)
            if (data_array[in_m] > root_val)
                break;
        root->left = small(data_array, pre_l + 1, in_m - 1);
        root->right = small(data_array, in_m, pre_r);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
// @lc code=end

