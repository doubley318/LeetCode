#include "mylib.h"

class Solution
{
public:
    int fib(int n)
    {
        int l = 0, r = 1;
        if (n <= 1)
            return n;
        for (int i = 1; i < n; i++)
        {
            int tmp = (l + r) % 1000000008;
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