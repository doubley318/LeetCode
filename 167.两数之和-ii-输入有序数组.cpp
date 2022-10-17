/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组
 */

// @lc code=start
class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int l = 0, r = numbers.size() - 1;
        int sum = numbers[l] + numbers[r];
        while (l < r)
        {
            if (sum < target)
                l++;
            else if (sum > target)
                r--;
            else
                return {l + 1, r + 1};
            sum = numbers[l] + numbers[r];
        }
        return {l + 1, r + 1};
    }
};
// @lc code=end
