/*
 * @lc app=leetcode.cn id=2824 lang=cpp
 *
 * [2824] 统计和小于目标的下标对数目
 */

// @lc code=start
class Solution {
public:
    int countPairs(vector<int>& nums, int target)
    {
        vector<int> sta(101, 0);
        for (int i = 0; i < nums.size(); i++) {
            nums[i] += 50;
            sta[nums[i]]++;
        }
        int tmpsum = 0;
        for (int i = 0; i < 101; i++) {
            int tmp = tmpsum;
            if (sta[i] != 0) {
                tmpsum += sta[i];
            }
            sta[i] = tmp;
        }
        int ret = 0;
        target += 100;
        for (int i = 0; i < nums.size(); i++) {
            if (target - nums[i] >= 0) {
                if (target - nums[i] > 100) {
                    ret += tmpsum;
                } else {
                    ret += sta[target - nums[i]];
                }
                if (target - nums[i] > nums[i]) {
                    ret--;
                }
            }
        }
        return ret / 2;
    }
};
// @lc code=end
