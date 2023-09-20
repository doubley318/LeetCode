#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n;
int halfa, halfb;
vector<pair<pair<int, int>, int>> nums;
bool isfinded = false;

// 先找a，从大到小找
void Find(int t, int suma, int sumb, vector<int>& res)
{
    int a = nums[t].first.first;
    int b = nums[t].first.second;
    if (isfinded || suma + a > halfa || sumb + b > halfb
        || (suma + a == halfa && sumb + b != halfb)
        || (suma + a != halfa && sumb + b == halfb)) {
        return;
    }
    res.push_back(nums[t].second);
    if (suma + a == halfa && sumb + b == halfb) {
        isfinded = true;
        return;
    }
    for (int i = t + 1; !isfinded && i < n; i++) {
        Find(i, suma + a, sumb + b, res);
    }
    if (!isfinded)
        res.erase(res.end() - 1);
}

int main()
{
    cin >> n;
    nums = vector<pair<pair<int, int>, int>>(n);
    int suma = 0, sumb = 0;
    for (int i = 0; i < n; i++) {
        cin >> nums[i].first.first;
        cin >> nums[i].first.second;
        suma += nums[i].first.first;
        sumb += nums[i].first.second;
        nums[i].second = i + 1;
    }
    sort(nums.begin(), nums.end());
    if (suma % 2 != 0 || sumb % 2 != 0 || nums[n - 1].first.first > suma / 2 || nums[n - 1].first.second > sumb / 2) {
        cout << "-1" << endl;
        return 0;
    }
    halfa = suma / 2;
    halfb = sumb / 2;
    vector<int> res;
    Find(0, 0, 0, res);
    if (!isfinded) {
        cout << "-1" << endl;
        return 0;
    }
    cout << res.size() << " " << n - res.size() << endl;
    sort(res.begin(), res.end());
    vector<int> tmp(n + 1, 0);
    for (int i = 0; i < res.size(); i++) {
        tmp[res[i]] = 1;
        cout << res[i] << " ";
    }
    cout << endl;
    for (int i = 1; i <= n; i++) {
        if (tmp[i] == 0) {
            cout << i << " ";
        }
    }
    cout << endl;
    return 0;
}