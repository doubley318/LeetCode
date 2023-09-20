#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// 已经排好序的不用动，然后只需要抽出无序的。
int main()
{
    int T;
    cin >> T;
    while (T)
    {
        T--;
        int n, k;
        cin >> n >> k;
        int t = 1;
        for (int i = 0; i < n; i++)
        {
            int tmp;
            cin >> tmp;
            if (tmp == t)
            {
                t++;
            }
        }
        t--;
        cout << (n - t + k - 1) / k << endl;
    }
    return 0;
}