#include "mylib.h"

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int res = nums[0], tmp = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if (tmp < 0)
                tmp = 0;
            tmp = tmp + nums[i];
            res = max(res, tmp);
        }
        return res;
    }
};

int main()
{
    return 0;
}