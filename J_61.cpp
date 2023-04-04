#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    bool isStraight(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int numsofzero = 0;
        for (int i = 0; i < 5; i++)
        {
            if (nums[i] == 0)
                numsofzero++;
        }
        if (numsofzero >= 4)
            return true;
        if (nums[4] - nums[numsofzero] >= 5)
            return false;
        for (int i = numsofzero + 1; i < 5; i++)
            if (nums[i] == nums[i - 1])
                return false;
        return true;
    }
};
int main()
{
    return 0;
}