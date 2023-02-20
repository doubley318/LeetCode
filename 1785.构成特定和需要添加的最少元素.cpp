/*
 * @lc app=leetcode.cn id=1785 lang=cpp
 *
 * [1785] 构成特定和需要添加的最少元素
 */

// @lc code=start
class Solution
{
public:
    int minElements(vector<int> &nums, int limit, int goal)
    {
        int n = nums.size();
        long long sum = 0;
        for (int i = 0; i < n; i++)
            sum += nums[i];
        long long diff = sum - goal;
        if (diff % limit == 0)
            return abs(diff / limit);
        else
            return abs(diff / limit) + 1;
    }
};
// @lc code=end
