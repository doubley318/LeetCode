#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    int x;
    vector<int> num;
    int N = 7;
    while (N--)
    {
        cin >> x;
        num.push_back(x);
    }
    int n = num.size();
    // 1. 设置引流点，找最高的
    vector<int> my_dot;
    int l = 0, r = 2;
    for (int i = 1; i < n - 1; i++)
    {
        if (num[i] > num[l] && num[i] > num[r])
        {
            my_dot.push_back(i);
            l = i;
            r = i + 2;
        }
        else if (num[i] == num[r])
        {
            r += 2;
        }
        else
        {
            l = i;
            r = i + 2;
        }
    }
    if (r - l > 1)
        my_dot.push_back(l + 1);
    my_dot.push_back(n - 1);
    // 2. 找积水线
    vector<int> water(n, 10000000);
    water[0] = num[0];
    for (int i = 1; i < n; i++)
    {
        water[i] = min(num[i - 1], water[i - 1]);
    }
    water[n - 1] = num[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        water[i] = min(num[i + 1], water[i]);
    }
    // 3. 根据引流规则算引流量
    vector<int> liu(my_dot.size(), 0);
    int pointl = 0, pointr = 0;
    for (int i = 1; i < n - 1; i++)
    {
        if (pointl == pointr && i < my_dot[pointl])
        {
            liu[pointl] += num[i] - water[i];
        }
        else if (pointl == pointr && i == my_dot[pointl])
        {
            pointr++;
            liu[pointl] += num[i] - water[i];
        }
        else
        {
            if (num[my_dot[pointl]] >= num[my_dot[pointr]])
            {
                liu[pointl] += num[i] - water[i];
            }
            else
            {
                liu[pointr] += num[i] - water[i];
            }
            if (i == pointr)
            {
                pointr++;
                pointl++;
            }
        }
    }
    for (int i = 0; i < my_dot.size() - 1; i++)
    {
        cout << liu[i] << " ";
    }
    return 0;
}