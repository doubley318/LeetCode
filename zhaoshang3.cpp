#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int G = 0, L = 2147483647;
    vector<vector<int>> num(n, vector<int>(2, 0));
    string ope;
    int time;
    for (int i = 0; i < n; i++)
    {
        cin >> ope >> time;
        num[i][0] = time;
        if (ope == "L")
        {
            num[i][1] = 0;
        }
        else
        {
            num[i][1] = 1;
        }
    }
    int ans = 2147483647;
    for (int i = 0; i < n; i++)
    {
        int tmp = num[i][0];
        int ret = 0;
        for (int j = 0; j < n; j++)
        {
            if (num[j][1] == 0 && num[j][0] < tmp)
            {
                ret++;
            }
            if (num[j][1] == 1 && num[j][0] > tmp)
            {
                ret++;
            }
        }
        ans = min(ret, ans);
    }
    cout << ans << endl;
    return 0;
}
// 64 位输出请用 printf("%lld")
// 8
// L 10
// L 11
// L 12
// L 14
// G 1
// G 10
// G 11
// G 3