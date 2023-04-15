#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> matrix(n, vector<char>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
        }
    }
    int res = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < m - 1; j++)
        {
            int y = 0, u = 0, o = 0;
            for (int k = 0; k < 4; k++)
            {
                char tmp = matrix[i + k / 2][j + k % 2];
                if (tmp == 'y')
                    y++;
                else if (tmp == 'o')
                    o++;
                else if (tmp == 'u')
                    u++;
            }
            if (y > 0 && u > 0 && o > 0)
                res++;
        }
    }
    cout << res << endl;
    return 0;
}