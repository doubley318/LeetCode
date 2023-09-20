#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
#define M 1000000007

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n, 0);
    unordered_map<int, int> mp;
    unordered_set<int> se;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        mp[nums[i]]++;
        se.insert(nums[i]);
    }
    int ptrl = 0;
    for (int i = 1; i < n; i++) {
        if (nums[i] != nums[ptrl]) {
            ptrl++;
            nums[ptrl] = nums[i];
        }
    }
    n = ptrl + 1;
    if (n == 1) {
        cout << 0 << endl;
        return 0;
    }
    vector<vector<long long>> dp(3, vector<long long>(n, 0));
    long long res = 0;
    for (int i = 0; i < n - 1; i++) {
        dp[1][i] = (nums[i] ^ nums[i + 1]);
        res = (res + dp[1][i]) % M;
    }
    int tmp_n = n - 2;
    int d = 2, d_1 = 1, d_2 = 0;
    for (int i = 0; i < tmp_n; tmp_n--) {
        for (int j = 0; j < tmp_n; j++) {
            dp[d][j] = (dp[d_1][j] + dp[d_1][j + 1] - dp[d_2][j + 1] + (nums[j] ^ nums[j + n - tmp_n])) % M;
            res = (res + dp[d][j]) % M;
            // cout << dp[d_1][j] << " " << dp[d_1][j + 1] << " " << dp[d_2][j + 1] << endl;
            // cout << j << " " << j + n - tmp_n + 1 << endl;
            // cout << (nums[j] ^ nums[j + n - tmp_n]) << endl;
        }
        d = (d + 1) % 3;
        d_1 = (d_1 + 1) % 3;
        d_2 = (d_2 + 1) % 3;
    }
    vector<int> hhh;
    for (auto i : se) {
        hhh.push_back(i);
    }
    for (auto i : mp) {
        for (int s = 0; i.second > 1 && s < se.size(); s++) {
            res = (res + (long long)(i.first ^ hhh[s]) * i.second) % M;
        }
    }
    cout << res << endl;
    return 0;
}