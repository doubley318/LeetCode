#include "mylib.h"

class Solution
{
public:
    int minimumRecolors(string blocks, int k)
    {
        int n = blocks.size();
        int l = 0, r = 0;
        int res = 0;
        for (; r < l + k; r++)
        {
            if (blocks[r] == 'W')
                res++;
        }
        int tmp = res;
        while (r < n)
        {
            if (blocks[r] == 'W')
                tmp++;
            if (blocks[l] == 'W')
                tmp--;
            res = min(res, tmp);
            r++;
            l--;
        }
        return res;
    }
};

int main()
{
    Solution so;
    return 0;
}