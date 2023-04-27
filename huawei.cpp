#include <iostream>
#include <map>
using namespace std;

int ans = 0;

bool del(string s, int l)
{
    if (l == s.size())
        return true;
    if (l > s.size())
        return false;
    int tmp = 0;
    int i = l;
    while (i < s.size() && s[i] <= '9' && s[i] >= '0')
    {
        tmp = tmp * 10 + s[i] - '0';
        if (del(s, tmp + i + 1))
        {
            int tmp_i = i + 1;
            if (tmp_i < s.size() && s[tmp_i] <= '9' && s[i] >= '0')
            {
                int tmp_tmp = tmp * 10 + s[tmp_i] - '0';
                if (del(s, tmp_tmp + tmp_i + 1))
                {
                    ans++;
                }
            }
            return true;
        }
        i++;
    }
    return false;
}

int main()
{
    string s;
    // 9abshwjxns
    // 109jskskwkxi
    // 1sjw
    cin >> s;
    if (del(s, 0))
    {
        if (ans == 0)
            cout << "yes" << endl;
        else
            cout << "two" << endl;
    }
    else
        cout << "no" << endl;
    return 0;
}