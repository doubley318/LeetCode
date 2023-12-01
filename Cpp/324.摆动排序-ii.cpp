/*
 * @lc app=leetcode.cn id=324 lang=cpp
 *
 * [324] 摆动排序 II
 */

// @lc code=start
class Solution
{
public:
    void wiggleSort(vector<int> &nums)
    {
        vector<int> A((nums.size() + 1) / 2);
        vector<int> B(nums.size() / 2);
        sort(nums.begin(), nums.end());
        for (int i = 0; i < (nums.size() + 1) / 2; i++)
        {
            A[i] = nums[(nums.size() + 1) / 2 - i - 1];
        }
        for (int i = 0; i < (nums.size() / 2); i++)
        {
            B[i] = nums[(nums.size() - i - 1)];
        }
        for (int i = 0; i < nums.size(); i++)
        {
            nums[i] = i % 2 == 0 ? A[i / 2] : B[i / 2];
        }
    }
};
// @lc code=end
