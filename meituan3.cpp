#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int binfind(vector<long> nums, long q)
{
    int l = 0;
    int r = nums.size() - 1;
    int m;
    while (l <= r)
    {
        m = (l + r) / 2;
        if (nums[m] < q)
            l = m + 1;
        else if (nums[m] > q)
            r = m - 1;
        else
            return (m + 1);
    }
    return l;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<long> qclt(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> qclt[i];
        qclt[i] *= qclt[i];
    }
    sort(qclt.begin(), qclt.end());
    vector<long> q(m, 0);
    for (int i = 0; i < m; i++)
    {
        cin >> q[i];
    }
    for (int i = 1; i < n; i++)
    {
        qclt[i] += qclt[i - 1];
    }
    for (int i = 0; i < m; i++)
    {
        cout << binfind(qclt, q[i]) << endl;
    }
    return 0;
}