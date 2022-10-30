#include "mylib.h"
class Solution1
{
public:
    long long makeIntegerBeautiful(long long n, int target)
    {
        int n_sum = 0;
        long long tmp_n = n;
        while (tmp_n != 0)
        {
            n_sum += tmp_n % 10;
            tmp_n /= 10;
        }
        if (n_sum <= target)
            return 0;
        n_sum -= target;
        string s = to_string(n);
        int tmp_sum = 0, i;
        for (i = s.size() - 1; tmp_sum - 1 < n_sum && i >= 0; i--)
        {
            tmp_sum += s[i] - '0';
        }
        if (i == -1)
            return pow(10, s.size()) - n;
        else
        {
            long long t = pow(10, s.size() - i - 1);
            return (n / t + 1) * t - n;
        }
    }
};

class Solution2
{
public:
    int check_sum(long long n)
    {
        string s = to_string(n);
        int ret = 0;
        for (int i = 0; i < s.size(); i++)
        {
            ret += s[i] - '0';
        }
        return ret;
    }

    long long makeIntegerBeautiful(long long n, int target)
    {
        long long tmp = n;
        int i = 0;
        while (check_sum(tmp) > target)
        {
            long long t = pow(10, i);
            tmp = ((n / t) + 1) * t;
            i++;
        }
        return tmp - n;
    }
};