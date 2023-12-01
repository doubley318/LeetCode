/*
 * @lc app=leetcode.cn id=2341 lang=cpp
 *
 * [2341] 数组能形成多少数对
 */

// @lc code=start
class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        vector<int> res(2, 0);
        vector<int> mark(101, 0);
        for (int i = 0; i < nums.size(); i++)
        {
            mark[nums[i]]++;
        }
        for (int i = 0; i <= 100; i++)
        {
            res[0] += mark[i] / 2;
            res[1] += mark[i] % 2;
        }
        return res;
    }
};
// @lc code=end

