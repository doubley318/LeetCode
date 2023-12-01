#include <iostream>
#include <math.h>
#include <unordered_set>
#include <vector>
using namespace std;

int main()
{
    int n, h;
    cin >> n >> h;
    int cards1 = 0;
    int cards2 = 0;
    vector<int> nums2;
    for (int i = 0; i < n; i++) {
        int t, x;
        cin >> t >> x;
        if (t == 1) {
            cards1 += x;
        } else {
            cards2 += x;
        }
    }
    int l = cards1, r = cards1 * 6;
    h = h - cards2;
    if (cards2 <= 0 || h > r) {
        cout << 0 << endl;
        return 0;
    }
    if (h <= l) {
        cout << 1 << endl;
        return 0;
    }
    

    return 0;
}