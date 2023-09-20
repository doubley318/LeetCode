#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{

    vector<int> nums(1005, 0);
    int x, n = 0;
    int m;
    while (cin >> x) {
        nums[n] = x;
        n++;
    }
    n = n - 1;
    m = nums[n];
    int l = 0, r = n - 1;
    while (l < r) {
        if (nums[l] + nums[r] == m) {
            cout << "1 " << nums[l] << " " << nums[r] << endl;
            break;
        } else if (nums[l] + nums[r] > m) {
            r--;
        } else {
            l++;
        }
    }
    if (l >= r) {
        cout << "0 0 0" << endl;
    }
    return 0;
}