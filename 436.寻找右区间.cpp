/*
 * @lc app=leetcode.cn id=436 lang=cpp
 *
 * [436] 寻找右区间
 */

// @lc code=start
class Solution
{
public:
    vector<int> findRightInterval(vector<vector<int>> &intervals)
    {
        vector<pair<int, int>> start;
        vector<pair<int, int>> end;
        for (int i = 0; i < intervals.size(); i++)
        {
            start.push_back({intervals[i][0], i});
            end.push_back({intervals[i][1], i});
        }
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        vector<int> ans(intervals.size());
        int left = 0;
        for (int i = 0; i < intervals.size(); i++)
        {
            while (left < intervals.size() && start[left].first < end[i].first)
                left++;
            ans[end[i].second] = left < intervals.size() ? start[left].second : -1;
        }
        return ans;
    }
};
// @lc code=end
