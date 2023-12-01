/*
 * @lc app=leetcode.cn id=1710 lang=cpp
 *
 * [1710] 卡车上的最大单元数
 */

// @lc code=start
class Solution
{
    struct cmp
    {
        vector<int> a;
        vector<int> b;
        bool operator()(vector<int> a, vector<int> b)
        {
            return a[1] > b[1];
        }
    };

public:
    int maximumUnits(vector<vector<int>> &nums, int truckSize)
    {
        sort(nums.begin(), nums.end(), cmp());
        int ret = 0, i = 0;
        while (truckSize > 0 && i < nums.size())
        {
            if (truckSize >= nums[i][0])
            {
                ret = ret + nums[i][0] * nums[i][1];
                truckSize -= nums[i][0];
            }
            else
            {
                ret = ret + truckSize * nums[i][1];
                truckSize = 0;
            }
            i++;
        }
        return ret;
    }
};
// @lc code=end
