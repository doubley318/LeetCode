#include "mylib.h"

class Solution
{
public:
    int minDeletion(vector<int> &nums)
    {
        int i, j;
        int tmp = 0;
        int res = 0;
        for (i = 0; i != nums.size();)
        {
            if (tmp % 2 == 0)
            {
                j = i + 1;
                while (j != nums.size() && nums[i] == nums[j])
                {
                    j++;
                    res++;
                }
                i = j;
            }
            else
                i++;
            tmp++;
        }
        if (tmp % 2 == 1)
            return res + 1;
        return res;
    }
};

int main()
{
    Solution so;
    vector<int> nums = {1, 2};
    cout << so.minDeletion(nums) << endl;
    return 0;
}