#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    // 保证最后也是递增的，那么最后就是从m-i，m
    int zeng = 1, pre = 1;
    cout << 1 << " ";
    for (int i = 1; i < n; i++) {
        int tmp = pre + zeng;
        if (m - tmp >= n - i - 1) {
            cout << tmp << " ";
            pre = tmp;
            zeng++;
        } else {
            cout << pre + 1 << " ";
            pre = pre + 1;
        }
    }
    return 0;
}