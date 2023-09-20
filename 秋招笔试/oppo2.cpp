#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#define ll long long
using namespace std;

int main()
{
    ll l1, r1, l2, r2;
    cin >> l1 >> r1 >> l2 >> r2;
    ll tmp1 = (l1 + l2) / 2;
    ll tmp2 = (r1 + r2) / 2;
    cout << tmp2 - tmp1 + 1 << endl;
    return 0;
}