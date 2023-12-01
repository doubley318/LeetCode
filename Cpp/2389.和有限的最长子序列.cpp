/*
 * @lc app=leetcode.cn id=2389 lang=cpp
 *
 * [2389] 和有限的最长子序列
 */

// @lc code=start
class Solution
{
public:
    vector<int> answerQueries(vector<int> &nums, vector<int> &queries)
    {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++)
        {
            nums[i] = nums[i - 1] + nums[i];
        }
        for (int i = 0; i < queries.size(); i++)
        {
            int l = 0, r = nums.size() - 1;
            while (l <= r)
            {
                int m = l + (r - l) / 2;
                if (nums[m] < queries[i])
                    l = m + 1;
                else if (nums[m] > queries[i])
                    r = m - 1;
                else
                {
                    l = m + 1;
                    break;
                }
            }
            queries[i] = l;
        }
        return queries;
    }
};
// @lc code=end
