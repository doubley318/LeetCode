/*
 * @lc app=leetcode.cn id=228 lang=cpp
 *
 * [228] 汇总区间
 */

// @lc code=start
class Solution {
public:
    vector<string> summaryRanges(vector<int> &nums)
    {
        vector<string> ans;
        if (nums.size() == 0)
            return ans;
        int l = nums[0];
        int tmp = l;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] != tmp + 1)
            {
                if (tmp == l)
                    ans.push_back(to_string(tmp));
                else
                    ans.push_back(to_string(l) + "->" + to_string(tmp));
                tmp = nums[i];
                l = tmp;
            }
            else
                tmp++;
        }
        if (tmp == l)
            ans.push_back(to_string(tmp));
        else
            ans.push_back(to_string(l) + "->" + to_string(tmp));
        return ans;
    }
};
// @lc code=end

