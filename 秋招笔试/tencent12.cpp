#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> nums(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            cin >> nums[i];
        }
        vector<int> snums = nums;
        sort(snums.begin(), snums.end());
        int m = (1 + n) / 2;
        int l = m - 1, r = m + 1;
        if (n % 2 == 0) {
            printf("%.1lf ", (float)(snums[m] + snums[m + 1]) / 2);
        }
        int q, remain = n;
        for (int i = 0; i < n - 1; i++) {
            cin >> q;
            int delnum = nums[q];

            remain--;
            if (delnum <= snums[m]) {
                if (remain % 2 == 0) {
                }
            }
        }
    }
    return 0;
}