#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main()
{
    string s;
    cin >> s;
    stack<int> sta;
    sta.push(s[s.size() - 1] - '0');
    for (int i = s.size() - 2; i > 1; i--)
    {
        if (s[i] - '0' >= sta.top())
        {
            sta.push(s[i] - '0');
        }
    }
    string res = "0.";
    while (!sta.empty())
    {
        res = res + to_string(sta.top());
        sta.pop();
    }
    cout << res;
    return 0;
}