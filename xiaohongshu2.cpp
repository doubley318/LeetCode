#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> num(n);
    int tmp_min = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
        tmp_min = max(num[i], tmp_min);
    }
    if (k == 1)
    {
        cout << max(num[0], num[n - 1]) << endl;
    }
    else
    {
        cout << tmp_min << endl;
    }
    return 0;
}