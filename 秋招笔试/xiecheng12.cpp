#include <iostream>
#include <math.h>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<string> strs(n);
    for (int i = 0; i < n; i++) {
        cin >> strs[i];
    }
    vector<vector<int>> dprow(n, vector<int>(3, 0));
    vector<vector<int>> dpcol(m, vector<int>(3, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (strs[i][j] == 'y') {
                dprow[i][0]++;
                dpcol[j][0]++;
            } else if (strs[i][j] == 'o') {
                dprow[i][1]++;
                dpcol[j][1]++;
            } else if (strs[i][j] == 'u') {
                dprow[i][2]++;
                dpcol[j][2]++;
            }
        }
    }
    long long res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (strs[i][j] == 'y') {
                res += dprow[i][1] * dpcol[j][2] + dprow[i][2] * dpcol[j][1];
            } else if (strs[i][j] == 'o') {
                res += dprow[i][0] * dpcol[j][2] + dprow[i][2] * dpcol[j][0];
            } else if (strs[i][j] == 'u') {
                res += dprow[i][1] * dpcol[j][0] + dprow[i][0] * dpcol[j][1];
            }
        }
    }
    cout << res << endl;
    return 0;
}