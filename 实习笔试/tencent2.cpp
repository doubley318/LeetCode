#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int N = pow(2, n) - 1;
    vector<int> seq(N);
    for (int i = 0; i < N; i++)
        cin >> seq[i];
    map<int, pair<int, int>> my_map;
    int l, r;
    for (int i = 0; i < N; i++)
    {
        l = (i + 1) * 2 - 1;
        r = l + 1;
        if (r < N)
            my_map[seq[i]] = make_pair(seq[l], seq[r]);
        else
            my_map[seq[i]] = make_pair(-1, -1);
    }
    int q;
    cin >> q;
    while (q)
    {
        q--;
        int x;
        cin >> x;
        if (my_map.find(x) != my_map.end())
        {
            cout << "YES" << endl;
            if (my_map[x].first != -1)
                cout << my_map[x].first << " " << my_map[x].second << endl;
            else
                cout << "LEAF" << endl;
        }
        else
            cout << "NO" << endl;
    }
    return 0;
}