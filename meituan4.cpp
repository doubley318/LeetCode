#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;
int main()
{
    string S;
    cin >> S;
    int l = 0;
    map<string, string> dir;
    while (l < S.size())
    {
        string key;
        string val;
        while (l < S.size() && S[l] != '=')
        {
            key = key + S[l];
            l++;
        }
        l++;
        while (l < S.size() && S[l] != ';')
        {
            val = val + S[l];
            l++;
        }
        l++;
        dir[key] = val;
    }
    int q;
    cin >> q;
    string tmp;
    for (int i = 0; i < q; i++)
    {
        cin >> tmp;
        if (dir.count(tmp) != 0)
            cout << dir[tmp] << endl;
        else
            cout << "EMPTY" << endl;
    }
    return 0;
}