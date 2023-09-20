/*
 * @lc app=leetcode.cn id=435 lang=cpp
 *
 * [435] 无重叠区间
 */

// @lc code=start
class Solution {
public:
    static bool cmp(const vector<int> &a, const vector<int> &b)
    {
        return a[1] < b[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals)
    {
        int n = intervals.size(), del = 0;
        if (n == 0) {
            return 0;
        }
        sort(intervals.begin(), intervals.end(), cmp);
        int r = intervals[0][1];
        for (int i = 1; i < n; i++) {
            if (intervals[i][0] < r) {
                del++;
            } else {
                r = intervals[i][1];
            }
        }
        return del;
    }
};
// @lc code=end
