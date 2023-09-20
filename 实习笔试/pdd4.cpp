#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t)
    {
        t--;
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
        }
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            int mark = 0, tmp = nums[n - 1];
            for (int j = n - 1; j >= 0; j--)
            {
                if (nums[j] > tmp)
                {
                    tmp = nums[j];
                    mark = 1;
                    break;
                }
                tmp = nums[j];
            }
            if (mark == 0)
            {
                break;
            }
            for (int j = 0; j < n; j++)
            {
                if (nums[j] == tmp)
                    nums[j] = 0;
            }
            res++;
        }
        cout << res << endl;
    }
    return 0;
}