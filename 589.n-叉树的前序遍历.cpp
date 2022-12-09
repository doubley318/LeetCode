/*
 * @lc app=leetcode.cn id=589 lang=cpp
 *
 * [589] N 叉树的前序遍历
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

class Solution
{
public:
    vector<int> preorder(Node *root)
    {
        vector<int> ret;
        stack<Node *> sta;
        if (root == nullptr)
            return ret;
        sta.push(root);
        while (!sta.empty())
        {
            Node *tmp = sta.top();
            ret.push_back(tmp->val);
            sta.pop();
            for (int i = tmp->children.size() - 1; i >= 0; i--)
            {
                sta.push(tmp->children[i]);
            }
        }
        return ret;
    }
};
// @lc code=end
