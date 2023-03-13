#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    struct cmp
    {
        bool operator()(int a, int b)
        {
            string tmpa = to_string(a);
            string tmpb = to_string(b);
            return tmpa + tmpb < tmpb + tmpa;
        }
    };

    string minNumber(vector<int> &nums)
    {
        sort(nums.begin(), nums.end(), cmp());
        string res;
        for (int i = 0; i < nums.size(); i++)
            res += to_string(nums[i]);
        return res;
    }
};

int main()
{
    Solution so;
    vector<int> nums = {10, 1, 2};
    cout << so.minNumber(nums) << endl;
    return 0;
}