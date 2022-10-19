/*
 * @lc app=leetcode.cn id=414 lang=cpp
 *
 * [414] 第三大的数
 */

// @lc code=start
class Solution
{
public:
    int thirdMax(vector<int> &nums)
    {
        int *a = nullptr, *b = nullptr, *c = nullptr;
        for (int i = 0; i < nums.size(); i++)
        {
            if (a == nullptr || nums[i] > *a)
            {
                c = b;
                b = a;
                a = &nums[i];
            }
            else if (*a > nums[i] && (b == nullptr || nums[i] > *b))
            {
                c = b;
                b = &nums[i];
            }
            else if ((b != nullptr && *b > nums[i]) && (c == nullptr || nums[i] > *c))
                c = &nums[i];
        }
        return c == nullptr ? *a : *c;
    }
};
// @lc code=end
