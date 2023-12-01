#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int l = 0, r = nums.size() - 1;
        while (l < r && nums[l] + nums[r] != target)
        {
            if (nums[l] + nums[r] > target)
                r--;
            else if (nums[l] + nums[r] < target)
                l++;
        }
        return vector<int>{nums[l], nums[r]};
    }
};

int main()
{
    return 0;
}