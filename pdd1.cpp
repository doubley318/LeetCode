#include <iostream>
#include <vector>
using namespace std;
// 动态规划
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
    for (int i = 1; i <= n; i++)
    {
        char man;
        cin >> man;
        if (man == 'b')
        {
            for (int j = 1; j <= i; j++)
            {
                dp[j][i] = dp[j][i - 1];
            }
        }
        else
        {
            for(int j=1;j<=i;j++)
            {
                
            }
        }
    }
    return 0;
}