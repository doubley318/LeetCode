#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n, 0);
    vector<int> b(n, 0);
    vector<long long> nums(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int j = 0; j < n; j++) {
        cin >> b[j];
    }
    for (int i = 0; i < n; i++) {
        nums[i] = a[i] - b[i];
    }
    long long MaxRes = 0, MinRes = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] > 0) {
            MaxRes += nums[i];
        } else {
            MinRes += nums[i];
        }
    }
    cout << max(MaxRes, -MinRes) << endl;
    return 0;
}