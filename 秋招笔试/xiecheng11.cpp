#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

bool isPrimer(int x)
{
    vector<int> p = { 3, 5, 7, 11, 13, 17, 19 };
    for (int& i : p) {
        if (x == i) {
            return true;
        }
    }
    return false;
}

void dfs(vector<vector<bool>>& dp, int t, vector<bool>& v, int n, long long& res)
{
    v[t] = true;
    for (int i = 1; i <= n; i++) {
        if (dp[t][i] && !v[i]) {
            dfs(dp, i, v, n, res);
        }
    }
    bool y = true;
    for (int i = 1; i <= n; i++) {
        if (!v[i]) {
            y = false;
            break;
        }
    }
    if (y) {
        res++;
    }
    v[t] = false;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<bool>> dp(n + 1, vector<bool>(n + 1, false));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i != j) {
                if (!isPrimer(i + j)) {
                    dp[i][j] = true;
                }
            }
        }
    }
    long long res = 0;
    vector<bool> v(n + 1, false);
    for (int i = 1; i <= n; i++) {
        dfs(dp, i, v, n, res);
    }
    cout << res << endl;
    return 0;
}
// 2:0
// 3:0
// 4: