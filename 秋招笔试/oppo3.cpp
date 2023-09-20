#include <iostream>
#include <math.h>
#include <vector>
#define INT_MAX 2100000000
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n, 0);
    vector<int> b(n, 0);
    long long tta = 0, ttb = 0;
    int maxa1 = 0, mina1 = INT_MAX;
    int maxa2 = 0, mina2 = INT_MAX;
    int maxb1 = 0, minb1 = INT_MAX;
    int maxb2 = 0, minb2 = INT_MAX;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        tta = tta + a[i];
        ttb = ttb + b[i];
        // max
        if (a[i] >= maxa1) {
            maxa2 = maxa1;
            maxa1 = a[i];
        } else if (a[i] > maxa2) {
            maxa2 = a[i];
        }
        if (b[i] >= maxb1) {
            maxb2 = maxb1;
            maxb1 = b[i];
        } else if (b[i] > maxb2) {
            maxb2 = b[i];
        }
        // min
        if (a[i] <= mina1) {
            mina2 = mina1;
            mina1 = a[i];
        } else if (a[i] < mina2) {
            mina2 = a[i];
        }
        if (b[i] <= minb1) {
            minb2 = minb1;
            minb1 = b[i];
        } else if (b[i] < minb2) {
            minb2 = b[i];
        }
    }

    int N = n - 3;
    for (int i = 0; i < n; i++) {
        double tmpa = tta - a[i];
        if (a[i] == maxa1) {
            tmpa = tmpa - maxa2 - mina1;
        } else if (a[i] == mina1) {
            tmpa = tmpa - maxa1 - mina2;
        } else {
            tmpa = tmpa - maxa1 - mina1;
        }
        double tmpb = ttb - b[i];
        if (b[i] == maxb1) {
            tmpb = tmpb - maxb2 - minb1;
        } else if (b[i] == minb1) {
            tmpb = tmpb - maxb1 - minb2;
        } else {
            tmpb = tmpb - maxb1 - minb1;
        }
        cout << (tmpa / N + tmpb / N) / 2 << endl;
    }
    return 0;
}