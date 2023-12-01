/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */

// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int> &nums)
    {
        if (nums.size() == 1)
            return;
        int tmp = 0;
        for (int i = nums.size() - 1; i > 0; i--)
        {
            if (nums[i] > nums[i - 1])
            {
                for (int j = nums.size() - 1; j >= i; j--)
                {
                    if (nums[j] > nums[i - 1])
                    {
                        tmp = 1;
                        int t = nums[j];
                        nums[j] = nums[i - 1];
                        nums[i - 1] = t;
                        break;
                    }
                }
                if (tmp == 1)
                {
                    for (int j = i; j < (nums.size() + i) / 2; j++)
                    {
                        int k = nums[j];
                        nums[j] = nums[nums.size() - 1 - j + i];
                        nums[nums.size() - 1 - j + i] = k;
                    }
                    return;
                }
            }
        }
        for (int i = 0; i < (nums.size()) / 2; i++)
        {
            int k = nums[i];
            nums[i] = nums[nums.size() - 1 - i];
            nums[nums.size() - 1 - i] = k;
        }
        return;
    }
};
// @lc code=end

