#include "mylib.h"

class Solution
{
public:
    int numWays(int n)
    {
        if (n == 0)
            return 1;
        int l = 1, r = 2;
        if (n <= 2)
            return n;
        for (int i = 2; i < n; i++)
        {
            int tmp = (l + r) % 1000000007;
            l = r;
            r = tmp;
        }
        return r;
    }
};

int main()
{
    return 0;
}