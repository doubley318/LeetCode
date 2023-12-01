#include "mylib.h"

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int res = 0, tmp = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            tmp += prices[i] - prices[i - 1];
            if (tmp <= 0)
                tmp = 0;
            res = max(res, tmp);
        }
        return res;
    }
};

int main()
{
    return 0;
}