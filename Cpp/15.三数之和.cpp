/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> res;
        if (nums.size() < 3)
            return res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; i++)
        {
            if (nums[i] > 0)
                return res;
            int l = i + 1;
            int r = nums.size() - 1;
            int tmp = nums[l];
            for (; l < r;)
            {
                if (nums[i] + nums[l] + nums[r] == 0)
                {
                    vector<int> t(3);
                    t[0] = nums[i];
                    t[1] = nums[l];
                    t[2] = nums[r];
                    res.push_back(t);
                    while (l < r && nums[l] == nums[l + 1])
                        l++;
                    while (r > l && nums[r] == nums[r - 1])
                        r--;
                    l++;
                }
                else if (nums[i] + nums[l] + nums[r] < 0)
                    l++;
                else
                    r--;
            }
            while (i+1 < nums.size() && nums[i] == nums[i + 1])
                i++;
        }
        return res;
    }
};
// @lc code=end
