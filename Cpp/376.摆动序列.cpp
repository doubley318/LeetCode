/*
 * @lc app=leetcode.cn id=376 lang=cpp
 *
 * [376] 摆动序列
 */

// @lc code=start
class Solution
{
public:
    int wiggleMaxLength(vector<int> &nums)
    {
        int ret = 1;
        int pre = nums[0];
        int bool_add = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > pre)
            {
                if (bool_add != 1)
                {
                    bool_add = 1;
                    ret++;
                }
            }
            else if (nums[i] < pre)
            {
                if (bool_add != -1)
                {
                    bool_add = -1;
                    ret++;
                }
            }
            pre = nums[i];
        }
        return ret;
    }
};
// @lc code=end
