#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());
    long long l = 0, r = 0;
    for (int i = 0; i < n / 2; i++) {
        l += nums[i];
    }
    for (int i = n / 2; i < n; i++) {
        r += nums[i];
    }
    cout << r - l << endl;
    return 0;
}