/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */

// @lc code=start
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int res = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < nums.size() - 2; i++)
        {
            if (nums[i] > target / 3)
                return res;
            int l = i + 1;
            int r = nums.size() - 1;
            int tmp = nums[l];
            for (; l < r && res != target;)
            {
                int t = nums[i] + nums[l] + nums[r];
                res = abs(t - target) > abs(res - target) ? res : t;
                while (l < r - 1 && nums[l] == nums[l + 2])
                    l++;
                while (r > l + 1 && nums[r] == nums[r - 2])
                    r--;
                if (nums[i] + nums[l] + nums[r] < target)
                    l++;
                else
                    r--;
            }
            while (i + 1 < nums.size() && nums[i] == nums[i + 1])
                i++;
        }
        return res;
    }
};
// @lc code=end

