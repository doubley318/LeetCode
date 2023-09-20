#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

// 判断d天生产的糖果包数
long long isOK(vector<int>& sw, long long d, int b)
{
    long long tmp = 0;
    for (auto& i : sw) {
        tmp += d * i / b;
    }
    return tmp;
}

int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> sweet(n, 0);
    int maxs = 0;
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> sweet[i];
        sum += sweet[i];
        maxs = max(maxs, sweet[i]);
    }
    long long l = (long long)a * b / sum, r = (long long)a * b / maxs;
    while (l < r) {
        long long m = (l + r) / 2;
        if (isOK(sweet, m, b) >= a) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    cout << r << endl;
    return 0;
}