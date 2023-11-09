/*
 * @lc app=leetcode.cn id=2300 lang=cpp
 *
 * [2300] 咒语和药水的成功对数
 */

// @lc code=start
class Solution {
public:
    int myLowerBound(const vector<int>& nums, double x)
    {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (nums[m] >= x) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return l;
    }

    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success)
    {
        sort(potions.begin(), potions.end());
        int n = spells.size(), m = potions.size();
        vector<int> ret(n, 0);
        for (int i = 0; i < n; i++) {
            ret[i] = m - myLowerBound(potions, (double)success / spells[i]);
        }
        return ret;
    }
};
// @lc code=end
