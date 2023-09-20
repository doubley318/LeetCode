#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

// yyyy-MM-ddThh:mm:ss
bool isYear(string& s, int l)
{
    if (l + 3 >= s.length())
        return false;
    for (int i = l; i < l + 4; i++) {
        if (s[i] > '9' || s[i] < '0') {
            return false;
        }
    }
    return true;
}

bool isMonth(string& s, int l)
{
    if (l + 1 >= s.length())
        return false;
    if (s[l] == '0' && (s[l + 1] >= '1' && s[l + 1] <= '9')) {
        return true;
    }
    if (s[l] == '1' && (s[l + 1] == '0' || s[l + 1] == '1' || s[l + 1] == '2')) {
        return true;
    }
    return false;
}

bool isDay(string& s, int l)
{
    if (l + 1 >= s.length())
        return false;
    bool tmp_res = false;
    if ((s[l] >= '0' && s[l] <= '2') && (s[l + 1] >= '1' && s[l + 1] <= '9')) {
        tmp_res = true;
    }
    if (s[l] == '3' && (s[l + 1] == '0' || s[l + 1] == '1')) {
        tmp_res = true;
    }
    if (tmp_res == false) {
        return false;
    }
    int tmp_l = l - 8;
    int years = stoi(s.substr(tmp_l, 4));
    int months = stoi(s.substr(tmp_l + 5, 2));
    int days = stoi(s.substr(l, 2));
    if (months == 4 || months == 6 || months == 9 || months == 11) {
        if (days > 30) {
            return false;
        }
    }
    if (months == 2) {
        if (days > 29) {
            return false;
        }
        if (!(years % 400 == 0 || (years % 100 != 0 && years % 4 == 0))) {
            if (days > 28) {
                return false;
            }
        }
    }
    return true;
}

bool isHour(string& s, int l)
{
    if (l + 1 >= s.length())
        return false;
    if ((s[l] == '0' || s[l] == '1') && (s[l + 1] >= '0' && s[l + 1] <= '9')) {
        return true;
    }
    if (s[l] == '2' && (s[l + 1] >= '0' && s[l + 1] <= '3')) {
        return true;
    }
    return false;
}

bool ism_s(string& s, int l)
{
    if (l + 1 >= s.length())
        return false;
    if (s[l] >= '0' && s[l] <= '5' && s[l + 1] >= '0' && s[l + 1] <= '9') {
        return true;
    }
    return false;
}

string getTime(string& s)
{
    int n = s.length();
    for (int i = 0; i <= n - 19; i++) {
        if (isYear(s, i) && isMonth(s, i + 5) && isDay(s, i + 8) && isHour(s, i + 11) && ism_s(s, i + 14) && ism_s(s, i + 17)) {
            if (s[i + 4] == '-' && s[i + 7] == '-' && s[i + 10] == 'T' && s[i + 13] == ':' && s[i + 16] == ':') {
                return s.substr(i, 19);
            }
        }
    }
    return "";
}

bool cmp(pair<string, string> x, pair<string, string> y)
{
    if (x.first < y.first) {
        return true;
    } else if (x.first > y.first) {
        return false;
    }
    if (x.second.length() < y.second.length()) {
        return true;
    } else if (x.second.length() > y.second.length()) {
        return true;
    }
    return x.second < y.second;
}

int main()
{
    int n;
    cin >> n;
    string s;
    unordered_set<string> SetString;
    while (n--) {
        cin >> s;
        SetString.insert(s);
    }
    if (SetString.size() == 0) {
        cout << endl;
    }
    n = SetString.size();
    vector<pair<string, string>> res(n);
    int tmp = 0;
    for (auto i : SetString) {
        res[tmp] = make_pair(getTime(i), i);
        tmp++;
    }
    sort(res.begin(), res.end(), cmp);
    for (int i = 0; i < n; i++) {
        cout << res[i].second << endl;
    }
    return 0;
}