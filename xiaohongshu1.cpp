#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main()
{
    long long A, B, M;
    cin >> A >> B >> M;
    vector<long long> num(50005, 0);
    num[0] = 1;
    num[1] = 1;
    int tmp_max = 1;
    int n;
    cin >> n;
    while (n--)
    {
        int q;
        cin >> q;
        for (int i = tmp_max; i < q; i++)
        {
            num[i + 1] = (A * num[i] + B * num[i - 1]) % M;
        }
        tmp_max = max(tmp_max, q);
        cout << num[q] << " ";
    }
    return 0;
}