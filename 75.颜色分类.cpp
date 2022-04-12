/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */

// @lc code=start
class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int a = 0, b = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
                a++;
            else if (nums[i] == 1)
                b++;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (a > 0)
                nums[i] = 0, a--;
            else if (b > 0)
                nums[i] = 1, b--;
            else
                nums[i] = 2;
        }
    }
};
// @lc code=end
