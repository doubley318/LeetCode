#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++)
        s[i] = s[i] - 3 < 'a' ? s[i] + 23 : s[i] - 3;
    cout << s << endl;
    return 0;
}