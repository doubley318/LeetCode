#include "mylib.h"

class Solution
{
public:
    int minMaxDifference(int num)
    {
        string snum = to_string(num);
        int n = snum.size();
        char cmax = '9', cmin = snum[0];
        for (int i = 0; i < n; i++)
        {
            if (snum[i] != '9')
            {
                cmax = snum[i];
                break;
            }
        }
        string smax, smin;
        for (int i = 0; i < n; i++)
        {
            if (snum[i] == cmax)
                smax += '9';
            else
                smax += snum[i];
            if (snum[i] == cmin)
                smin += '0';
            else
                smin += snum[i];
        }
        return stoi(smax) - stoi(smin);
    }
};

int main()
{
    Solution so;
    return 0;
}