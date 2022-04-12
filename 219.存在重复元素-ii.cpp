/*
 * @lc app=leetcode.cn id=219 lang=cpp
 *
 * [219] 存在重复元素 II
 */

// @lc code=start
class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        map<int, int> nummap;
        for (int l = 0; l < nums.size(); l++)
        {
            if (nummap.find(nums[l]) == nummap.end())
                nummap.insert(pair<int, int>(nums[l], l));
            else
            {
                if (l - nummap.find(nums[l])->second <= k)
                    return true;
                else
                    nummap.find(nums[l])->second = l;
            }
        }
        return false;
    }
};
// @lc code=end
