/*
 * @lc app=leetcode.cn id=429 lang=cpp
 *
 * [429] N 叉树的层序遍历
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node *root)
    {
        vector<vector<int>> ans;
        if (root == nullptr)
            return ans;
        ans = bfs(root, ans, 0);
        return ans;
    }

    vector<vector<int>> bfs(Node *root, vector<vector<int>> &ans, int level)
    {
        if (ans.size() < level + 1)
            ans.push_back(vector<int>());
        ans[level].push_back(root->val);
        if (root->children.size() == 0)
            return ans;
        queue<Node *> child;
        // vector<int> ans0;
        for (int i = 0; i < root->children.size(); i++)
        {
            child.push(root->children[i]);
            // ans0.push_back(root->children[i]->val);
        }
        // ans.push_back(ans0);
        level++;
        while (!child.empty())
        {
            ans = bfs(child.front(), ans, level);
            child.pop();
        }
        return ans;
    }
};
// @lc code=end

