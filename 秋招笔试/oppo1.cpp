#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string s, t, target;
    cin >> s >> t >> target;
    for (int i = 0; i < n; i++) {
        if (target[i] != s[i] && target[i] != t[i]) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}