/*
 * @lc app=leetcode.cn id=1760 lang=cpp
 *
 * [1760] 袋子里最少数目的球
 */

// @lc code=start
class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {

        int l = 1, r = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            r = max(r, nums[i]);
        }
        while (l < r)
        {
            int m = (l + r) / 2;
            int op = 0;
            for (int i = 0; i < n; i++)
            {
                op += (nums[i] - 1) / m;
            }
            if (op <= maxOperations)
                r = m;
            else
                l = m + 1;
        }
        return l;
    }
};
// @lc code=end

