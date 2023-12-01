/*
 * @lc app=leetcode.cn id=229 lang=cpp
 *
 * [229] 多数元素 II
 */

// @lc code=start
class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        vector<int> ret;
        int element1 = 0, element2 = 0;
        int vote1 = 0, vote2 = 0;
        for (auto num : nums)
        {
            if (vote1 > 0 && element1 == num)
                vote1++;
            else if (vote2 > 0 && element2 == num)
                vote2++;
            else if (vote1 == 0)
            {
                vote1++;
                element1 = num;
            }
            else if (vote2 == 0)
            {
                vote2++;
                element2 = num;
            }
            else
            {
                vote1--;
                vote2--;
            }
        }
        vote1 = 0;
        vote2 = 0;
        for (auto num : nums)
        {
            if (num == element1)
                vote1++;
            else if (num == element2)
                vote2++;
        }
        if (vote1 > nums.size() / 3)
            ret.push_back(element1);
        if (vote2 > nums.size() / 3)
            ret.push_back(element2);
        return ret;
    }
};
// @lc code=end
