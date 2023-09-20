#include <iostream>
#include <limits.h>
using namespace std;

int strToInt(string str)
{
    bool sign = true, validNum = false;
    int res = 0;
    for (int i = 0; i < str.length(); i++) {
        char c = str[i];
        if (!validNum) {
            if (c == ' ') {
                continue;
            } else if (c == '-') {
                sign = false;
                validNum = true;
            } else if (c == '+') {
                validNum = true;
            } else if (c <= '9' && c >= '0') {
                validNum = true;
                i--;
            } else {
                return res;
            }
        } else {
            if (c <= '9' && c >= '0') {
                long long tmp = (long long)res * 10 + (sign ? (c - '0') : ('0' - c));
                if (tmp > INT_MAX || tmp < INT_MIN) {
                    return sign ? INT_MAX : INT_MIN;
                }
                res = tmp;
            } else {
                return res;
            }
        }
    }
    return res;
}
int main()
{
    string s = "   -91283472332";
    cout << strToInt(s) << endl;
    return 0;
}