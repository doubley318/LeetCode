#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

pair<int, int> cacu(int x)
{
    int number2 = 0;
    int number5 = 0;
    int tmp = x;
    while (tmp % 2 == 0)
    {
        tmp /= 2;
        number2++;
    }
    tmp = x;
    while (tmp % 5 == 0)
    {
        tmp /= 5;
        number5++;
    }
    return make_pair(number2, number5);
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> my_tree(n + 5);
    vector<pair<int, int>> init_number(n + 5, {0, 0});
    vector<pair<int, int>> oper_number(n + 5, {0, 0});
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        pair<int, int> tmp = cacu(x);
        init_number[i].first = tmp.first;
        init_number[i].second = tmp.second;
    }
    for (int i = 0; i < n - 1; i++)
    {
        int f, son;
        cin >> f >> son;
        my_tree[f].push_back(son);
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int f, x;
        cin >> f >> x;
        pair<int, int> tmp = cacu(x);
        oper_number[f].first += tmp.first;
        oper_number[f].second += tmp.second;
    }
    queue<int> que;
    vector<int> father(n + 5, 0);
    que.push(1);
    while (!que.empty())
    {
        int x = que.size();
        for (int i = 0; i < x; i++)
        {
            int t = que.front();
            que.pop();
            for (int j = 0; j < my_tree[t].size(); j++)
            {
                oper_number[my_tree[t][j]].first += oper_number[t].first;
                oper_number[my_tree[t][j]].second += oper_number[t].second;
                que.push(my_tree[t][j]);
                father[my_tree[t][j]] = t;
            }
        }
    }
    vector<int> res(n + 5, 0);
    vector<int> mark(n + 5, 0);
    for (int i = 1; i < n + 1; i++)
    {
        int j = 1;
        for (; j < n + 1; j++)
        {
            if (mark[j] != 1 && my_tree[j].size() == 0)
                break;
        }
        for (auto i = my_tree[father[j]].begin(); i != my_tree[father[j]].end(); i++)
        {
            if (*i == j)
            {
                my_tree[father[j]].erase(i);
                break;
            }
        }
        res[j] = min(init_number[j].first + oper_number[j].first, init_number[j].second + oper_number[j].second);
        oper_number[father[j]].first += oper_number[j].first + init_number[j].first;
        oper_number[father[j]].second += oper_number[j].second + init_number[j].second;
        mark[j] = 1;
    }
    for (int i = 1; i < n + 1; i++)
        cout << res[i] << " ";
    return 0;
}