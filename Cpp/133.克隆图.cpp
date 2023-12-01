/*
 * @lc app=leetcode.cn id=133 lang=cpp
 *
 * [133] 克隆图
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node* ,Node*>hash;
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        return dfs(node);       
    }
    Node* dfs(Node* node)   
    {
        //node节点已经被访问过了,直接从哈希表hash中取出对应的克隆节点返回。
        if(hash[node])  return hash[node]; 
        Node* clone = new Node(node->val); //克隆节点
        hash[node] = clone;                //建立源节点到克隆节点的映射
        for(Node* ver: node->neighbors)    //克隆边
        {
            clone->neighbors.push_back(dfs(ver));
        }
        return clone;
    }
};
// @lc code=end
