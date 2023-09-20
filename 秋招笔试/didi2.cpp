#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 判断s1的前面和s2的后面匹配的最大长度
int pi1(const string& s1, const string& s2)
{
    int n1 = s1.length(), n2 = s2.length();
    int p = 1;
    while (p < n2) {
        bool tmp = true;
        for (int i = 0; tmp && i < n1 && (i + p) < n2; i++) {
            if (s1[i] != s2[i + p]) {
                p++;
                tmp = false;
                break;
            }
        }
        if (tmp) {
            return n2 - p;
        }
    }
    return 0;
}

// 判断s1的后面和s1的前面匹配的最大长度
int pi2(const string& s1, const string& s2)
{
    int n1 = s1.length(), n2 = s2.length();
    int p = n2 - 2;
    while (p >= 0) {
        bool tmp = true;
        for (int i = n1 - 1; tmp && i >= 0 && (p - (n1 - 1 - i)) >= 0; i--) {
            if (s1[i] != s2[p - (n1 - 1 - i)]) {
                p--;
                tmp = false;
                break;
            }
        }
        if (tmp) {
            return p + 1;
        }
    }
    return 0;
}
int main()
{
    int n;
    cin >> n;
    vector<string> S(n);
    for (int i = 0; i < n; i++) {
        cin >> S[i];
    }
    vector<vector<int>> nums(n, vector<int>(2, 0));
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int qian = pi1(S[i], S[j]);
            int hou = pi2(S[i], S[j]);
            nums[i][0] = max(nums[i][0], qian);
            nums[i][1] = max(nums[i][1], hou);
            nums[j][0] = max(nums[j][0], hou);
            nums[j][1] = max(nums[j][1], qian);
        }
    }
    vector<string> res(n);
    int res_size = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i][0] + nums[i][1] >= S[i].length()) {
            res[res_size] = S[i];
            res_size++;
        }
    }
    sort(res.begin(), res.begin() + res_size);
    cout << res_size << endl;
    for (int i = 0; i < res_size; i++) {
        cout << res[i] << endl;
    }
    return 0;
}