#include <iostream>
#include <string>
using namespace std;

int getDigit(string& s, int& ptr)
{
    int res = 0;
    while (ptr < s.length() && s[ptr] <= '9' && s[ptr] >= '0') {
        res = res * 10 + s[ptr] - '0';
        ptr++;
    }
    return res;
}

int main()
{
    string s;
    cin >> s;
    int n = s.length();
    int ptr = 0, res = 0;
    res = getDigit(s, ptr);
    while (ptr < n) {
        if (s[ptr] == '=') {
            break;
        }
        if (s[ptr++] == '+') {
            res += getDigit(s, ptr);
        } else {
            res -= getDigit(s, ptr);
        }
    }
    cout << res << endl;
    return 0;
}