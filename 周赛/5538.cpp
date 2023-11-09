#include "mylib.h"

class Solution
{
public:
    vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2)
    {
        vector<vector<int>> res(2, vector<int>(0, 0));
        set<int> n1;
        set<int> n2;
        for (int i : nums1)
            n1.insert(i);
        for (int i : nums2)
            n2.insert(i);
        for (int i : n1)
            if (n2.count(i) == 0)
                res[0].push_back(i);
        for (int i : n2)
            if (n1.count(i) == 0)
                res[1].push_back(i);
        return res;
    }
};

int main()
{
    Solution so;
    vector<int> nums1 = {1, 1, 2, 3};
    vector<int> nums2 = {3, 4, 4, 2};
    vector<vector<int>> nums(2, vector<int>(3));
    nums = so.findDifference(nums1, nums2);
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = 0; j < nums[0].size(); j++)
        {
            cout << nums[i][j] << ",";
        }
        cout << endl;
    }
    return 0;
}