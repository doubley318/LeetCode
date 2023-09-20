#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

long long n_mul(int n)
{
    // 我写的是
    // long long res = 1;
    // while (n > 1)
    // {
    //     res = (res * n) % 1000000007;
    //     n--;
    // }
    // return res;

    // 实际应该是：
    return n * (n + 1) / 2;
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n, 0);
    long long res = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        res = (res + n_mul(a[i])) % 1000000007;
    }
    for (int i = 1; i < n - 1; i++)
    {
        int l = i - 1, r = i + 1;
        while (l >= 0 && r < n)
        {
            res = (res + min(a[l], a[r])) % 1000000007;
            if (a[l] != a[r])
                break;
            l--;
            r++;
        }
    }
    cout << res << endl;
    return 0;
}