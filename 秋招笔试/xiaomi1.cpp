#include <iostream>
#include <math.h>
#include <string>
#include <vector>
using namespace std;

vector<int> mysplit(string s)
{
    vector<int> res;
    int tmp = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ',') {
            res.push_back(tmp);
            tmp = 0;
        } else {
            tmp = tmp * 10 + s[i] - '0';
        }
    }
    res.push_back(tmp);
    return res;
}

inline float dis(float x1, float y1, float x2, float y2)
{
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main()
{
    string s;
    cin >> s;
    int n, R;
    vector<int> tmp = mysplit(s);
    n = tmp[0], R = tmp[1];
    vector<vector<int>> mp(n, vector<int>(3, 0));
    for (int i = 0; i < n; i++) {
        cin >> s;
        mp[i] = mysplit(s);
    }
    int maxq = 0;
    int x = 0, y = 0;
    for (int i = 0; i <= 100; i++) {
        for (int j = 0; j <= 100; j++) {
            int tmp = 0;
            for (int k = 0; k < n; k++) {
                float d = dis(i, j, mp[k][0], mp[k][1]);
                if (d > R) {
                    continue;
                }
                tmp += (float)mp[k][2] / (1 + d);
            }
            if (tmp > maxq) {
                maxq = tmp;
                x = i, y = j;
            }
        }
    }
    cout << x << ',' << y << endl;
    return 0;
}