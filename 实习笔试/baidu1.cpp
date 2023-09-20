#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
using namespace std;
#define INT_MAX 2100000000
int main()
{
    int n;
    cin >> n;
    vector<int> ball(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> ball[i];
    }
    string color;
    cin >> color;
    unordered_map<int, int> green;
    unordered_map<int, int> red;
    long res = 0;
    for (int i = 0; i < n; i++)
    {
        if (color[i] == 'R')
            green[ball[i]]++;
        else
            red[ball[i]]++;
    }
    vector<long> last_green(green.size());
    vector<long> last_red(red.size());
    int mark = 0;
    for (auto i = green.begin(); i != green.end(); i++)
    {
        last_green[mark] = (i->first * i->second) % 1000000007;
        mark++;
    }
    mark = 0;
    for (auto j = red.begin(); j != red.end(); j++)
    {
        last_red[mark] = (j->first * j->second) % 1000000007;
        mark++;
    }
    for (int i = 0; i < last_green.size(); i++)
    {
        for (int j = 0; j < last_red.size(); j++)
        {
            res = (res + last_green[i] * last_red[j]) % 1000000007;
        }
    }
    cout << res << endl;
    return 0;
}