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
    vector<int> my_L;
    vector<int> my_G;
    string ope;
    int time;
    for (int i = 0; i < n; i++)
    {
        cin >> ope >> time;
        if (ope == "L")
        {
            L = min(L, time);
            my_L.emplace_back(time);
        }
        else
        {
            G = max(G, time);
            my_G.emplace_back(time);
        }
    }
    if (my_L.size() == 0 || my_G.size() == 0)
    {
        cout << "0" << endl;
    }
    else
    {
        sort(my_L.begin(), my_L.end());
        sort(my_G.begin(), my_G.end());
        if (my_L[0] >= my_G[my_G.size() - 1])
        {
            cout << "0" << endl;
        }
        else
        {
            int tmp = 0;
            for (int i = my_G.size() - 1; i >= 0 && my_L[0] < my_G[i]; i--)
            {
                tmp++;
            }
            int tmp1 = 0;
            for (int i = 0; i < my_L.size() && my_G[my_G.size() - 1] > my_L[i]; i++)
            {
                tmp1++;
            }
            cout << min(tmp, tmp1) << endl;
        }
    }

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