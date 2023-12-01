/*
 * @lc app=leetcode.cn id=2216 lang=cpp
 *
 * [2216] 美化数组的最少删除数
 */

// @lc code=start
class Solution {
public:
    int minDeletion(vector<int>& nums)
    {
        int ret = 0;
        // 真下标
        int n = nums.size();
        if (n == 1) {
            return 1;
        }
        int tmp = 0;
        for (int i = 1; i < n; i++) {
            while (i < n && nums[tmp] == nums[i]) {
                i++;
                ret++;
            }
            if (i == n - 2) {
                return ret + 1;
            } else if (i < n) {
                tmp = i + 1;
                i++;
            } else {
                return ret + 1;
            }
        }
        return ret;
    }
};
// @lc code=end
