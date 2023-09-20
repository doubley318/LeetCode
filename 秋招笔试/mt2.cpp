#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<long long> nums(n, 0);
    vector<long long> Sum(n, 0);
    long long tmp_sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        Sum[i] = tmp_sum;
        tmp_sum += nums[i];
    }
    long long res = tmp_sum;
    for (int i = 1; i < n; i++) {
        if (Sum[i] - nums[i] >= 0) {
            res = min(res, tmp_sum - nums[i] * 2);
        }
    }
    if (res == tmp_sum) {
        cout << -1 << endl;
    } else {
        cout << res << endl;
    }
    return 0;
}