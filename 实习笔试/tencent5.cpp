#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> my_map(n, vector<int>(m, 0));
    vector<vector<pair<int, int>>> my_map2(n, vector<pair<int, int>>(m));
    vector<vector<char>> my_map3(n, vector<char>(m));
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
        {
            my_map3[i][j] = s[j];
        }
    }
    for (int i = 1; i < m; i++)
    {
        if (my_map3[0][i] == '#')
            my_map2[0][i] = make_pair(0, 0);
        else if (my_map2[0][i - 1].first == 0)
            my_map2[0][i] = make_pair(1, 1);
        else
            my_map2[0][i].first = (my_map2[0][i - 1].first * 2) % 1000000007;
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            
        }
    }
    string s;
}