/*
 * @lc app=leetcode.cn id=57 lang=cpp
 *
 * [57] 插入区间
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval)
    {
        int n = intervals.size();
        int L = newInterval[0], R = newInterval[1];
        vector<vector<int>> res;
        if (n == 0) {
            return { { L, R } };
        }
        int l = -1, r = -1;
        for (int i = 0; i < n; i++) {
            if (l == -1) {
                if (intervals[i][0] >= L) {
                    l = L;
                } else if (intervals[i][1] >= R) {
                    return intervals;
                } else if (intervals[i][1] >= L) {
                    l = intervals[i][0];
                }
            }
            if (l != -1) {
                if (intervals[i][0] > R) {
                    r = R;
                } else if (intervals[i][1] >= R) {
                    r = intervals[i][1];
                }
                if (r != -1) {
                    res.push_back({ l, r });
                    if (r == intervals[i][1])
                        i++;
                    while (i < n) {
                        res.push_back(intervals[i]);
                        i++;
                    }
                    return res;
                }
            }
            if (l == -1 && r == -1) {
                res.push_back({ intervals[i][0], intervals[i][1] });
            }
        }
        if (l == -1) {
            l = L;
        }
        if (r == -1) {
            res.push_back({ l, R });
        }
        return res;
    }
};
// @lc code=end
