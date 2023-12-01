#include <iostream>
#include <math.h>
#include <unordered_set>
#include <vector>
using namespace std;
#define M 1000000007

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n, 0);
    vector<long long> pre(n, 0);
    long long res = 0;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        if (i != 0)
            pre[i] = pre[i - 1] + nums[i - 1];
    }
    long long tmp = 0;
    for (int i = 1; i < n; i++) {
        tmp = (tmp + pre[i]) % M;
        res = (res + tmp * nums[i]) % M;
    }
    cout << res << endl;
    return 0;
}