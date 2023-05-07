#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

int test()
{
    int n;
    cin >> n;
    vector<int> num(n);
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }
    int times;
    cin >> times;
    while (times)
    {
        times--;
        int a, b;
        cin >> a >> b;
        vector<int> tmp = num;
        tmp[a - 1] = b;
        sort(tmp.begin(), tmp.end());
        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += tmp[i] * (n - i);
        }
        cout << sum << endl;
    }
    return 0;
}

int main()
{
    // vector<int> a = {1, 2, 3, 5, 6, 8};
    // cout << my_search(a, 100) << endl;
    test();
    return 0;
}
// 9
// 1 10 17 4 6 5 27 18 25
// 6
// 3 20
// 2 4
// 2 1
// 3 1
// 5 10
// 6 8
// 7 18