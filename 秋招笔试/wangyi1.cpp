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
        vector<int> nums(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        if (n % 2 == 1) {
            cout << "YES" << endl;
        } else {
            vector<int> nums1(n / 2, 0);
            vector<int> nums2(n / 2, 0);
            for (int i = 0; i < n / 2; i++) {
                nums1[i] = nums[i * 2];
                nums2[i] = nums[i * 2 + 1];
            }
            sort(nums1.begin(), nums1.end());
            sort(nums2.begin(), nums2.end());
            bool yes = true;
            for (int i = 0; i < n / 2; i++) {
                if (nums2[i] < nums1[i]) {
                    yes = false;
                    break;
                }
                if (i != 0 && nums1[i] < nums2[i - 1]) {
                    yes = false;
                    break;
                }
            }
            if (yes) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}