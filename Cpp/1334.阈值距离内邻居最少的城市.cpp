/*
 * @lc app=leetcode.cn id=1334 lang=cpp
 *
 * [1334] 阈值距离内邻居最少的城市
 */

// @lc code=start
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold)
    {
        vector<vector<int>> m(n, vector<int>(n, 1e9));
        for (int i = 0; i < edges.size(); i++) {
            m[edges[i][0]][edges[i][1]] = edges[i][2];
            m[edges[i][1]][edges[i][0]] = edges[i][2];
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    if (j != k) {
                        m[j][k] = min(m[j][i] + m[i][k], m[j][k]);
                    }
                }
            }
        }
        int ret = 0;
        int tmp_min = 1e9;
        for (int i = 0; i < n; i++) {
            int tmp = 0;
            for (int j = 0; j < n; j++) {
                if (m[i][j] <= distanceThreshold) {
                    tmp++;
                }
            }
            if (tmp <= tmp_min) {
                tmp_min = tmp;
                ret = i;
            }
        }
        return ret;
    }
};
// @lc code=end
