/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> tmp;
        ans.push_back(tmp);
        for (int i = 0; i < nums.size(); i++)
        {
            int p = ans.size();
            for (int j = 0; j < p; j++)
            {
                tmp = ans[j];
                tmp.push_back(nums[i]);
                ans.push_back(tmp);
            }
        }
        return ans;
    }
};
// @lc code=end

