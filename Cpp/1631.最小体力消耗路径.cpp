/*
 * @lc app=leetcode.cn id=1631 lang=cpp
 *
 * [1631] 最小体力消耗路径
 */

// @lc code=start
class Solution {
public:
    bool dfs(int row, int col, const int n, const int m, vector<vector<int>>& mp, const int dis, vector<vector<bool>>& visit, bool& find)
    {
        if (row == n - 1 && col == m - 1) {
            find = true;
            return true;
        }
        visit[row][col] = true;
        bool ret = false;
        if (!find && row > 0 && abs(mp[row - 1][col] - mp[row][col]) <= dis && visit[row - 1][col] == false) {
            ret |= dfs(row - 1, col, n, m, mp, dis, visit, find);
        }
        if (!find && row < n - 1 && abs(mp[row + 1][col] - mp[row][col]) <= dis && visit[row + 1][col] == false) {
            ret |= dfs(row + 1, col, n, m, mp, dis, visit, find);
        }
        if (!find && col > 0 && abs(mp[row][col - 1] - mp[row][col]) <= dis && visit[row][col - 1] == false) {
            ret |= dfs(row, col - 1, n, m, mp, dis, visit, find);
        }
        if (!find && col < m - 1 && abs(mp[row][col + 1] - mp[row][col]) <= dis && visit[row][col + 1] == false) {
            ret |= dfs(row, col + 1, n, m, mp, dis, visit, find);
        }
        return ret;
    }

    int minimumEffortPath(vector<vector<int>>& heights)
    {
        // 二分法
        int n = heights.size(), m = heights[0].size();
        unordered_set<int> st;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i > 0) {
                    st.insert(abs(heights[i - 1][j] - heights[i][j]));
                }
                if (i < n - 1) {
                    st.insert(abs(heights[i + 1][j] - heights[i][j]));
                }
                if (j > 0) {
                    st.insert(abs(heights[i][j - 1] - heights[i][j]));
                }
                if (j < m - 1) {
                    st.insert(abs(heights[i][j + 1] - heights[i][j]));
                }
            }
        }
        if (st.size() == 0) {
            return 0;
        }
        vector<int> Ret;
        for (auto i : st) {
            Ret.push_back(i);
        }
        sort(Ret.begin(), Ret.end());
        int l = 0, r = Ret.size() - 1;
        while (l < r) {
            int mid = (l + r) / 2;
            vector<vector<bool>> visited(n, vector<bool>(m, false));
            bool find = false;
            if (dfs(0, 0, n, m, heights, Ret[mid], visited, find)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return Ret[l];
    }
};
// @lc code=end
