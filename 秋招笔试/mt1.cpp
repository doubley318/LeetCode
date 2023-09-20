#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int k;
    cin >> k;
    string res = s;
    while (k--) {
        string tmp = "";
        for (char& c : res) {
            if (c == 'a') {
                tmp += "bc";
            } else if (c == 'b') {
                tmp += "ca";
            } else if (c == 'c') {
                tmp += "ab";
            }
        }
        res = tmp;
    }
    cout << res << endl;
    return 0;
}