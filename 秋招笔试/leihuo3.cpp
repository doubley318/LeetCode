#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#define M 2100000000
using namespace std;

bool cmp(const vector<int>& x, const vector<int>& y)
{
    if (x[2] == y[2]) {
        return x[0] < y[0];
    }
    return x[2] < y[2];
}

int find2(const vector<vector<int>>& grass, int index, int num)
{
    // 找到第一个 >=num 的数字
    if (index == 2) {
        int l = 0, r = grass.size() - 1;
        while (l < r) {
            int m = (l + r) / 2;
            if (grass[m][index] >= num) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        return l;
    }
    return 1;
}

int K1(int Y, const vector<vector<int>>& grass)
{
    int f = find2(grass, 2, Y);
    if (grass[f][2] != Y) {
        return M;
    }
    return grass[f][0];
}

int K2(int Y, const vector<vector<int>>& grass)
{
    int n = grass.size();
    int l = 0, r = n - 1;
    int res = M;
    while (l < r) {
        int tmp = grass[l][2] + grass[r][2];
        if (tmp > Y) {
            r--;
        } else if (tmp < Y) {
            l++;
        } else {
            res = min(res, grass[l][0] + grass[r][0]);
            r--;
        }
    }
    return res;
}

int K3(int Y, const vector<vector<int>>& grass)
{
    int n = grass.size();
    int res = M;
    for (int i = 0; i < n - 2; i++) {
        int l = i + 1, r = n - 1;
        while (l < r) {
            int tmp = grass[i][2] + grass[l][2] + grass[r][2];
            if (tmp > Y) {
                r--;
            } else if (tmp < Y) {
                l++;
            } else {
                res = min(res, grass[i][0] + grass[l][0] + grass[r][0]);
                r--;
            }
        }
    }
    return res;
}

int K4(int Y, const vector<vector<int>>& grass)
{
    int n = grass.size();
    int res = M;
    for (int k = 0; k < n - 3; k++) {
        for (int i = k + 1; i < n - 2; i++) {
            int l = i + 1, r = n - 1;
            while (l < r) {
                int tmp = grass[i][2] + grass[l][2] + grass[r][2] + grass[k][2];
                if (tmp > Y) {
                    r--;
                } else if (tmp < Y) {
                    l++;
                } else {
                    res = min(res, grass[i][0] + grass[l][0] + grass[r][0] + grass[k][0]);
                    r--;
                }
            }
        }
    }
    return res;
}

int K5(int Y, const vector<vector<int>>& grass)
{
    int n = grass.size();
    int res = M;
    for (int j = 0; j < n - 4; j++) {
        for (int k = 0; k < n - 3; k++) {
            for (int i = k + 1; i < n - 2; i++) {
                int l = i + 1, r = n - 1;
                while (l < r) {
                    int tmp = grass[i][2] + grass[l][2] + grass[r][2] + grass[k][2];
                    if (tmp > Y) {
                        r--;
                    } else if (tmp < Y) {
                        l++;
                    } else {
                        res = min(res, grass[i][0] + grass[l][0] + grass[r][0] + grass[k][0]);
                        r--;
                    }
                }
            }
        }
    }
    return res;
}

/*
5 3 1 10
5 1 5
4 1 5
4 1 4
4 1 7
4 1 7
*/
int main()
{
    // 数量、上限、属性、属性值
    int N, K, X, Y;
    cin >> N >> K >> X >> Y;
    if (X == 1) {
        Y = -Y;
    }

    // 价值、属性、属性值
    vector<vector<int>> grass(N, vector<int>(3, 0));

    for (int i = 0; i < N; i++) {
        int D_v;
        cin >> grass[i][0] >> grass[i][1] >> D_v;
        if (grass[i][1] == 1) {
            grass[i][2] = -D_v;
        }
    }

    sort(grass.begin(), grass.end(), cmp);
    int cost = 0;
    if (K == 0) {
        cost = M;
    } else if (K == 1) {
        cost = K1(Y, grass);
    } else if (K == 2) {
        cost = min(K2(Y, grass), K1(Y, grass));
    } else if (K == 3) {
        cost = min(K3(Y, grass), min(K2(Y, grass), K1(Y, grass)));
    } else if (K == 4) {
        cost = min(K4(Y, grass), min(K3(Y, grass), min(K2(Y, grass), K1(Y, grass))));
    } else {
        cost = min(K5(Y, grass), min(K4(Y, grass), min(K3(Y, grass), min(K2(Y, grass), K1(Y, grass)))));
    }

    if (cost == M) {
        cout << "Cannot Make It!" << endl;
    } else {
        cout << cost << endl;
    }
    return 0;
}