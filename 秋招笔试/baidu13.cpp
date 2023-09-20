#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

struct node {
    // [l,r]
    int l;
    // [l,r]
    int r;
    // 最小值
    int M;
    // 需要加的值
    int a;
    node* left;
    node* right;
    node* father;
    node(int L, int R, int m)
        : l(L)
        , r(R)
        , M(m)
        , a(0)
        , left(nullptr)
        , right(nullptr)
        , father(nullptr) {};
};

void make(vector<node*>& son, vector<node*>& fa)
{
    for (int i = 0; i < fa.size(); i++) {
        fa[i] = new node(i * 2, i * 2 + 1, 0);
        fa[i]->left = son[i * 2];
        fa[i]->right = son[i * 2 + 1];
        son[i * 2]->father = fa[i];
        son[i * 2 + 1]->father = fa[i];
        fa[i]->M = min(son[i * 2]->M, son[i * 2 + 1]->M);
    }
}

bool bong = false;

void update(node* root, int l, int r)
{
    if (bong)
        return;
    if (root->l >= l && root->r <= r) {
        root->a++;
        if (root->a >= root->M) {
            bong = true;
        }
        return;
    }
    root->left->a += root->a;
    root->right->a += root->a;
    root->a = 0;
    if (root->r > r && root->l <= l) {
        update(root->left, l, r);
    }
    if (root->l < l && root->r >= r) {
        update(root->right, l, r);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    // 线段树
    vector<node*> tree(n);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        tree[i] = new node(i, i, a);
    }
    int tmp = n;
    vector<node*> son = tree;
    while (tmp > 1) {
        vector<node*> fa((tmp + 1) / 2);
        tmp = (tmp + 1) / 2;
        make(son, fa);
        son = fa;
    }
    node* root = son[0];
    vector<vector<int>> up(m, vector<int>(2, 0));
    int res = -1;
    for (int i = 0; !bong && i < m; i++) {
        cin >> up[i][0] >> up[i][1];
        update(root, up[i][0] - 1, up[i][1] - 1);
        if (bong) {
            res = i;
        }
    }
    res = res == -1 ? n : res;
    cout << res << endl;
    return 0;
}