#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    if (k == 1) {
        for (int i = n; i > 0; i--) {
            cout << i << " ";
        }
        return 0;
    }
    int p = k;
    for (int i = n; i > k; i--) {
        cout << i << " ";
    }
    for (int i = 1; i <= k; i++) {
        cout << i << " ";
    }
    return 0;
}