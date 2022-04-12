/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        if (nums.size() <= 3)
            return res;
        sort(nums.begin(), nums.end());
        int l, r, t;
        for (int i = 0; i < nums.size(); i++)
        {
            t = i + 1;
            for (int j = t; j < nums.size(); j++)
            {
                l = j + 1;
                r = nums.size() - 1;
                while (l < r)
                {
                    if ((double)nums[i] + nums[j] + nums[l] + nums[r] > INT_MAX||(double)nums[i] + nums[j] + nums[l] + nums[r]<INT_MIN)
                    {
                        r--;
                        continue;
                    }
                    if (nums[i] + nums[j] + nums[l] + nums[r] == target)
                    {
                        vector<int> ok(4);
                        ok[0] = nums[i];
                        ok[1] = nums[j];
                        ok[2] = nums[l];
                        ok[3] = nums[r];
                        res.push_back(ok);
                        while (l < r && nums[l] == nums[l + 1])
                            l++;
                        while (r > l && nums[r] == nums[r - 1])
                            r--;
                        l++;
                    }
                    else if (nums[i] + nums[j] + nums[l] + nums[r] < target)
                        l++;
                    else
                        r--;
                }
                while (j + 1 < nums.size() && nums[j] == nums[j + 1])
                    j++;
            }
            while (i + 2 < nums.size() && nums[i] == nums[i + 1])
                i++;
        }
        return res;
    }
};
// @lc code=end

