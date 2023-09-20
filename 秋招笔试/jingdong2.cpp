#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n + 5, 0);
    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
    }
    vector<long long> dp(n + 5, 0);
    for (int i = 2; i <= n; i++) {
        dp[i] = nums[i] + min(dp[i - 1], dp[i - 2]);
    }
    cout << dp[n] << endl;
    return 0;
}