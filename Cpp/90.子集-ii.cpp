/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> t;
        ans.push_back(t);
        int b = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int tmp = ans.size(), j;
            if (i - 1 >= 0 && nums[i] == nums[i - 1])
                j = b;
            else
                j = 0;
            b = tmp;
            for (; j < tmp; j++)
            {
                t = ans[j];
                t.push_back(nums[i]);
                ans.push_back(t);
            }
        }
        return ans;
    }
};
// @lc code=end
