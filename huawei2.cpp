#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main()
{
    int n;
    cin >> n;
    // -1表示有障碍物
    vector<int> my_dot(n + 5, 0);
    vector<vector<int>> my_tree(n + 5, vector<int>());
    vector<vector<int>> my_father(n + 5, vector<int>());
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        my_tree[a].push_back(b);
        my_father[b].push_back(a);
    }
    int x;
    cin >> x;
    for (int i = 0; i < x; i++)
    {
        int tmp;
        cin >> tmp;
        my_dot[tmp] = -1;
    }
    // bfs
    queue<int> my_que;
    if (my_dot[0] != -1)
        my_que.push(0);
    vector<vector<int>> res;
    while (!my_que.empty() && res.empty())
    {
        int tmp = my_que.size();
        for (int i = 0; i < tmp; i++)
        {
            int head = my_que.front();
            // 没有儿子，到了叶子节点
            if (my_tree[head].size() == 0)
            {
                int mark = head;
                vector<int> record;
                while (mark != 0)
                {
                    record.push_back(mark);
                    mark = my_father[mark][0];
                }
                record.push_back(mark);
                res.push_back(record);
            }
            for (int j = 0; j < my_tree[head].size(); j++)
            {
                if (my_dot[my_tree[head][j]] != -1)
                {
                    my_que.push(my_tree[head][j]);
                }
            }
            my_que.pop();
        }
    }
    if (res.empty())
    {
        cout << "NULL" << endl;
        return 0;
    }
    vector<int> record(res.size(), 0);
    int have = res.size();
    for (int j = res[0].size() - 1; j >= 0 && have > 1; j--)
    {
        int tmp = res[0][j];
        for (int i = 1; i < res.size(); i++)
        {
            tmp = tmp < res[i][j] ? tmp : res[i][j];
        }
        for (int i = 0; i < res.size(); i++)
        {
            if (res[i][j] != tmp)
            {
                if (record[i] == 0)
                {
                    have--;
                    record[i] = -1;
                }
            }
        }
    }
    for (int i = 0; i < res.size(); i++)
    {
        if (record[i] != -1)
        {
            cout << res[i][res[0].size() - 1];
            for (int j = res[0].size() - 2; j >= 0; j--)
            {
                cout << "->" << res[i][j];
            }
            cout << endl;
            return 0;
        }
    }
    return 0;
}