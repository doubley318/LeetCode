#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
// 线段树
int main()
{
    int n;
    cin >> n;
    vector<int> nums(n + 5, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> nums[i];
        if (nums[i] == -4)
            nums[i] = -3;
        else if (nums[i] == -8)
            nums[i] = -4;
        else if (nums[i] == 4)
            nums[i] = 3;
        else if (nums[i] == 8)
            nums[i] = 4;
    }
    vector<int> tmp = nums;
    int l = 1, r = 1;
    int count_fu = 0;
    int res_l, res_r, res = -1;
    int first_fu = -1, last_fu = -1;
    while (r <= n + 1)
    {
        if (nums[r] == 0)
        {
            if (count_fu % 2 == 0)
            {
                if (res < tmp[r - 1] || ((res == tmp[r - 1] && (res_r - res_l <= r - 1 - l))))
                {
                    res = tmp[r - 1];
                    res_l = l;
                    res_r = r - 1;
                }
            }
            else
            {
                if ((res < (tmp[r - 1] - tmp[first_fu]) || ((res == tmp[r - 1] - tmp[first_fu]) && (res_r - res_l <= r - 1 - first_fu))))
                {
                    res_l = first_fu + 1;
                    res_r = r - 1;
                    res = tmp[r - 1] - tmp[first_fu];
                }
                else
                {
                    res_l = l;
                    res_r = last_fu - 1;
                    res = tmp[last_fu - 1] - tmp[l - 1];
                }
            }
            l = r + 1;
            r++;
            count_fu = 0;
            continue;
        }
        else
        {
            if (nums[r] < 0)
            {
                count_fu++;
                if (first_fu == -1)
                    first_fu = r;
                else
                    last_fu = r;
            }
            tmp[r] = tmp[r - 1] + abs(tmp[r]) - 1;
        }
        r++;
    }
    if (res == -1)
        cout << -1 << endl;
    else
        cout << res_l << " " << res_r << endl;
    return 0;
}