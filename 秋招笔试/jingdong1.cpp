#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());
    long long res = 0;
    for (int i = n - 1; i > 0; i--) {
        if (nums[i] - nums[i - 1] <= k) {
            res = res + (long long)nums[i] * nums[i - 1];
            i--;
        }
    }
    cout << res << endl;
    return 0;
}