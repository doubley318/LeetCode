#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t)
    {
        t--;
        long long n;
        cin >> n;
        if (n == 2)
        {
            cout << 1 << " " << 1 << endl;
            continue;
        }
        // 两个相连的数字一定互质，最小公倍数一定是他们两个的乘积
        if (n % 2 == 1)
        {
            cout << n / 2 << " " << n / 2 + 1 << endl;
        }
        else
        {
            if (n / 2 % 2 == 0)
                cout << n / 2 - 1 << " " << n / 2 + 1 << endl;
            else
                cout << n / 2 - 2 << " " << n / 2 + 2 << endl;
        }
    }
    return 0;
}