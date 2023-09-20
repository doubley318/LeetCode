#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

int my_search(vector<int> num, int a)
{
    int l = 0, r = num.size() - 1;
    int m;
    while (l < r)
    {
        m = (l + r) / 2;
        if (num[m] < a)
        {
            l = m + 1;
        }
        else if (num[m] > a)
        {
            r = m;
        }
        else
        {
            return m;
        }
    }
    return l;
}

int test()
{
    int n;
    cin >> n;
    vector<int> num(n);
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }
    vector<int> so_num = num;
    sort(so_num.begin(), so_num.end());
    vector<long long> tmp_num(n, 0);
    long long SUM = 0;
    for (int i = 0; i < n; i++)
    {
        SUM = SUM + (long long)so_num[i] * (n - i);
        if (i == 0)
        {
            tmp_num[0] = so_num[0];
        }
        else
            tmp_num[i] = tmp_num[i - 1] + so_num[i];
    }
    int times;
    cin >> times;
    while (times)
    {
        times--;
        int a, b;
        cin >> a >> b;
        if (num[a - 1] == b)
        {
            cout << SUM << endl;
        }
        else
        {
            int location = my_search(so_num, num[a - 1]);
            if (num[a - 1] < b)
            {
                while (location < n && so_num[location] == num[a - 1])
                {
                    location++;
                }
                location--;
                long long tmp_sum = SUM - (n - location) * num[a - 1];
                if (b >= so_num[n - 1])
                {
                    tmp_sum = tmp_sum + tmp_num[n - 1] - tmp_num[location];
                    tmp_sum += (long long)b;
                }
                else
                {
                    int location_b = my_search(so_num, b);
                    tmp_sum += (long long)(n - location_b + 1) * b;
                    tmp_sum = tmp_sum + tmp_num[location_b - 1] - tmp_num[location];
                }
                cout << tmp_sum << endl;
            }
            else
            {
                while (location >= 0 && so_num[location] == num[a - 1])
                {
                    location--;
                }
                location++;
                long long tmp_sum = SUM - (n - location) * num[a - 1];
                if (b <= so_num[0])
                {
                    tmp_sum += (long long)b * n;
                    tmp_sum = tmp_sum - tmp_num[location - 1];
                }
                else
                {
                    int location_b = my_search(so_num, b);
                    tmp_sum += (long long)(n - location_b) * b;
                    tmp_sum = tmp_sum + tmp_num[location_b - 1] - tmp_num[location - 1];
                }
                cout << tmp_sum << endl;
            }
        }
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
// 5
// 1 10 3 4 6
// 1
// 3 20
// 2 4
// 2 1