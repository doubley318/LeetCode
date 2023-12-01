/*
 * @lc app=leetcode.cn id=260 lang=cpp
 *
 * [260] 只出现一次的数字 III
 */

// @lc code=start
class Solution
{
public:
    vector<int> singleNumber(vector<int> &nums)
    {

        int mask = 0;
        for (int i : nums)
            mask ^= i;
        mask = mask == INT_MIN ? mask : mask & (-mask);
        int one = 0, two = 0;
        for (int i : nums)
        {
            if (i & mask)
                one = i ^ one;
            else
                two = i ^ two;
        }
        return {one, two};
    }
};
// @lc code=end
