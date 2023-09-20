#include <iostream>
#include <string>
using namespace std;

inline int len(int x)
{
    int res = 0;
    while (x > 0) {
        x /= 10;
        res++;
    }
    return res;
}

int main()
{
    int x = 0;
    int p = 1;
    int n;
    cin >> n;
    while (p < n) {
        x += 2;
        if (p + len(x) < n) {
            p += len(x);
        } else {
            string s = to_string(x);
            cout << s[n - p - 1] << endl;
            return 0;
        }
    }
    cout << x << endl;
    return 0;
}