/*
 * @lc app=leetcode.cn id=2032 lang=cpp
 *
 * [2032] 至少在两个数组中出现的值
 */

// @lc code=start
class Solution
{
public:
    vector<int> twoOutOfThree(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3)
    {
        vector<int> x(105, 0);
        for (int i : nums1)
            x[i] = 1;
        for (int i : nums2)
        {
            if (x[i] == 1)
                x[i] = 3;
            else if (x[i] == 0)
                x[i] = 2;
        }
        for (int i : nums3)
            if (x[i] >= 1 && x[i] <= 3)
                x[i] += 3;
        vector<int> ret;
        for (int i = 0; i < 105; i++)
            if (x[i] >= 3)
                ret.push_back(i);
        return ret;
    }
};
// @lc code=end
