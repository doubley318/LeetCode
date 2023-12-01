#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<long long> a(n, 0);
    vector<long long> b(n, 0);
    long long suma = 0, sumb = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        suma += a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        sumb += b[i];
    }
    long long res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            res = max(res, max((suma - a[i]) ^ sumb, suma ^ (sumb - b[j])));
        }
    }
    cout << res << endl;
    return 0;
}