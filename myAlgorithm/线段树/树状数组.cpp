#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int val;
    Node()
        : val(0) {};
    Node(int v)
        : val(v) {};
};

int lowbit(int x)
{
    return x & (-x);
}

class Tree {
private:
    vector<Node> _tree;
    int n;

public:
    void build(const vector<int>& nums)
    {
        this->n = nums.size();
        this->_tree = vector<Node>(n + 1, 0);
        // 根据需求对节点进行操作，比如这里是求和
        // 那么已知一个节点n，则更新自己的父亲节点，父亲节点为n+lowbit(n)
        for (int i = 1; i <= n; i++) {
            _tree[i].val += nums[i - 1]; // 对节点的操作
            // 父亲节点
            int f = i + lowbit(i);
            if (f <= n) {
                _tree[f].val += _tree[i].val; // 对父亲节点的操作
            }
        }
    }

    // 对o节点进行某个操作，操作值为v
    void update(int o, int v)
    {
        while (o <= n) {
            _tree[o].val += v; // 对节点的操作
            o += lowbit(o);
        }
    }

    // 求[1, x]的值
    int subOp(int x)
    {
        int sum = 0;
        while (x > 0) {
            // x节点的管辖区域为[x-lowbit(x)+1,x]
            sum += _tree[x].val; // 对节点的操作
            x = x - lowbit(x);
        }
        return sum;
    }

    // 求[L, R]的值
    int Op(int L, int R)
    {
        // [1, R] - [1, L - 1]
        return subOp(R) - subOp(L - 1);
    }

    void Print()
    {
        for (int i = 1; i < this->_tree.size(); i++) {
            cout << this->_tree[i].val << " ";
        }
    }
};

int main()
{
    vector<int> nums = { 1, 2, 4, 62, 4, 67, 3 };
    Tree t;
    t.build(nums);
    t.Print();
    cout << t.Op(3, 5) << endl;
    return 0;
}