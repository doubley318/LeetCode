#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 1005, mod = 1e9 + 7;
LL a[maxn];

int main()
{
    int n;
    cin >> n;
    LL ans = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        ans = (ans + (a[i] + 1) * a[i] / 2) % mod;
    }
    for (int i = 1; i < n - 1; ++i)
    {
        bool flag = true;
        int j = i - 1, k = i + 1;
        while (j >= 0 && k < n && flag)
        {
            ans = (ans + min(a[k], a[j])) % mod;
            if (a[j--] != a[k++])
                flag = false;
        }
    }
    cout << ans << endl;
    return 0;
}