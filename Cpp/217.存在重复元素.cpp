/*
 * @lc app=leetcode.cn id=217 lang=cpp
 *
 * [217] 存在重复元素
 */

// @lc code=start
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> numset;
        for (int i = 0; i < nums.size(); i++)
        {
            if (numset.find(nums[i]) != numset.end())
                return true;
            numset.insert(nums[i]);
        }
        return false;
    }
};
// @lc code=end

