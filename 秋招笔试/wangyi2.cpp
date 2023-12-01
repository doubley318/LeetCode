#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    unordered_map<string, int> mp;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        vector<int> tmp(26, 0);
        for (int j = 0; j < s.length(); j++) {
            tmp[s[j] - 'a']++;
        }
        string x = "";
        for (int j = 0; j < 26; j++) {
            if (tmp[j] != 0) {
                x = x + (char)(j + 'a') + to_string(tmp[j]);
            }
        }
        mp[x]++;
    }
    long long res = 0;
    for (auto i : mp) {
        long long tmp = i.second;
        res += tmp * (tmp - 1) / 2;
    }
    cout << res << endl;
    return 0;
}