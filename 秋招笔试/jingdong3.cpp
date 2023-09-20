#include <algorithm>
#include <iostream>
#include <vector>
#define M 1000000007
using namespace std;

int main()
{
    int n;
    cin >> n;
    long long tmp, res = 0;
    for (int i = 1; i <= n; i++) {
        cin >> tmp;
        res = (res + tmp * (1 + i) * i / 2 * (n - i + 1)) % M;
    }
    cout << res << endl;
    return 0;
}