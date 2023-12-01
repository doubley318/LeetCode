#include <iostream>
#include <math.h>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int tmp = 0;
    int l, r;
    // 表示第i个任务有哪些孩子
    vector<vector<int>> son(n);
    // 入度
    vector<int> degree(n, 0);
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ':') {
            l = tmp;
            tmp = 0;
        } else if (s[i] == ',') {
            r = tmp;
            tmp = 0;
            son[r].push_back(l);
            degree[r]++;
        } else {
            tmp = tmp * 10 + s[i] - '0';
        }
    }
    son[tmp].push_back(l);
    degree[tmp]++;
    // 拓扑排序
    int isV = 0, preisV = -1;
    while (isV < n && preisV != isV) {
        preisV = isV;
        for (int i = 0; i < n; i++) {
            if (degree[i] == 0) {
                for (int j = 0; j < son[i].size(); j++) {
                    degree[son[i][j]]--;
                }
                isV++;
            }
        }
    }

    if (isV == n) {
        cout << 1 << endl;
    } else {
        cout << 0 << endl;
    }
    return 0;
}