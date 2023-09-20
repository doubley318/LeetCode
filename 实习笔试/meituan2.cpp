#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

inline int my_max(int a, int b, int c, int d, int e, int f)
{
    return max(max(max(max(max(a, b), c), d), e), f);
}

int main()
{
    int n;
    cin >> n;
    vector<int> sweet(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> sweet[i];
    }
    vector<vector<int>> dp(n + 3, vector<int>(3, 0));
    for (int i = 0; i < n; i++)
    {
        dp[i + 3][0] = my_max(dp[i][0], dp[i][1], dp[i][2], dp[i + 1][1], dp[i + 1][2], dp[i + 2][2]) + sweet[i];
        dp[i + 3][1] = dp[i + 2][0];
        dp[i + 3][2] = dp[i + 1][0];
    }
    cout << max(max(dp[n + 2][0], dp[n + 2][1]), dp[n + 2][2]) << endl;
    return 0;
}