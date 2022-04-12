#include "mylib.h"

class Solution
{
public:
    int largestInteger(int num)
    {
        string nums = to_string(num);
        for (int i = 0; i < nums.length(); i++)
        {
            if ((nums[i] - '0') % 2 == 0)
            {
                int j = i, k = i;
                while (j >= 0)
                {
                    if ((nums[j] - '0') % 2 == 0)
                        if (nums[j] < nums[k])
                            swap(nums[j], nums[k]), k = j;
                    j--;
                }
            }
            else
            {
                int j = i, k = i;
                while (j >= 0)
                {
                    if ((nums[j] - '0') % 2 == 1)
                        if (nums[j] < nums[k])
                            swap(nums[j], nums[k]), k = j;
                    j--;
                }
            }
        }
        return stoi(nums);
    }
};