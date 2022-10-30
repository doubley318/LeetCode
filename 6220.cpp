#include "mylib.h"
class Solution
{
public:
    int averageValue(vector<int> &nums)
    {
        int ret = 0, n = 0;
        for (int i : nums)
        {
            if (i % 6 == 0)
                ret += i, n++;
        }
        return n == 0 ? 0 : ret / n;
    }
};