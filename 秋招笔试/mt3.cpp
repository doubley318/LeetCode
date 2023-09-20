#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    stack<char> sta;
    for (int i = 0; i < n; i++) {
        if (!sta.empty() && s[i] == sta.top()) {
            sta.pop();
        } else {
            sta.push(s[i]);
        }
    }
    int len = sta.size();
    int tmp = len / 2;
    if (k < len) {
        cout << len - 2 * k << endl;
    } else {
        if (len % 2 == 0) {
            k = k - tmp;
            if (k % 2 == 0) {
                cout << 0 << endl;
            } else {
                cout << 2 << endl;
            }
        } else {
            cout << 1 << endl;
        }
    }
    if (len % 2 == 0) {
        int tmp = len / 2;
        if (k >= tmp) {
            k = k - tmp;
            if (k % 2 == 0) {
                cout << 0 << endl;
            } else {
                cout << 2 << endl;
            }
        } else {
            cout << len - 2 * k << endl;
        }
    } else {
        int tmp = len / 2;
        if (k >= tmp) {
            cout << 1 << endl;
        } else {
            cout << len - 2 * k << endl;
        }
    }
    return 0;
}