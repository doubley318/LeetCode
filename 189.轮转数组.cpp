/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 轮转数组
 */

// @lc code=start
class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        k = k % nums.size();
        reverse(nums.begin(), nums.end());
        auto i = nums.begin();
        for (int a = 0; a < k; a++)
            i++;
        reverse(nums.begin(), i);
        reverse(i, nums.end());
    }
};
// @lc code=end
