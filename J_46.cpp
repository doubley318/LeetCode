#include "mylib.h"

class Solution
{
public:
    int translateNum(int num)
    {
        string s = to_string(num);
        int n = s.size();
        int l = 1, r = 1;
        for (int i = 1; i < n; i++)
        {
            if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] < '6'))
            {
                int t = r;
                r = l + r;
                l = t;
            }
            else
                l = r;
        }
        return r;
    }
};

int main()
{
    return 0;
}