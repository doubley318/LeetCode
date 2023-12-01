/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end());
        int l = intervals[0][0], r = intervals[0][1];
        for (int i = 0; i < intervals.size(); i++)
        {
            if (r >= intervals[i][0])
                r = max(intervals[i][1], r);
            else
            {
                res.push_back(vector<int>{l, r});
                l = intervals[i][0];
                r = intervals[i][1];
            }
        }
        res.push_back(vector<int>{l, r});
        return res;
    }
};
// @lc code=end

