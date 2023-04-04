#include <iostream>
#include <vector>
using namespace std;

// 拓扑把最后且道路没坏的节点删掉
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> my_map(n + 5);
    vector<int> my_road(n + 5);
    vector<int> my_father(n + 5);
    for (int i = 0; i < n; i++)
    {
        int l, r, s;
        cin >> l >> r >> s;
        my_map[l].push_back(r);
        my_road[r] = s;
        my_father[r] = l;
    }
    for (int i = 0; i < n; i++)
    {
        int tmp = 0;
        for (int j = 1; j <= n; j++)
        {
            if (my_map[j].size() == 0)
            {
                if (my_road[j] == 1)
                {
                    my_map[j].push_back(-1);
                }
                else
                {
                    // 删除这个点；
                    my_map[j].push_back(-2);
                    for (auto k = my_map[my_father[j]].begin(); k != my_map[my_father[j]].end(); k++)
                    {
                        if ((*k) == j)
                        {
                            my_map[my_father[j]].erase(k);
                            break;
                        }
                    }
                }
                tmp = 1;
                break;
            }
        }
        if (tmp == 0)
            break;
    }
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        if (my_map[i].size() == 1 && my_map[i][0] == -1)
            res++;
    }
    cout << res << endl;
    return 0;
}