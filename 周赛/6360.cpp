#include "mylib.h"

class Solution
{
public:
    int minImpossibleOR(vector<int> &nums)
    {
        vector<int> off(31, 0);
        off[0] = 1;
        for (int i = 0; i < 30; i++)
        {
            off[i + 1] = off[i] << 1;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = 0; j < 31; j++)
            {
                if (off[j] == nums[i])
                    off[j] = 0;
            }
        }
        for (int i = 0; i < 31; i++)
        {
            if (off[i] != 0)
                return off[i];
        }
        return off[30];
    }
};

int main()
{
    Solution so;
    return 0;
}