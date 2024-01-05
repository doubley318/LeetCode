/*
 * @lc app=leetcode.cn id=2397 lang=cpp
 *
 * [2397] 被列覆盖的最多行数
 */

// @lc code=start
class Solution {
public:
    int Sum(vector<vector<int>> matrix, vector<int>& slt)
    {
        for (int i = 0; i < slt.size(); i++) {
            for (int j = 0; j < matrix.size(); j++) {
                matrix[j][slt[i]] = -matrix[j][slt[i]];
            }
        }
        int ret = 0;
        for (int i = 0; i < matrix.size(); i++) {
            bool s = true;
            for (int j = 0; s && j < matrix[0].size(); j++) {
                if (matrix[i][j] == 1) {
                    s = false;
                }
            }
            if (s) {
                ret++;
            }
        }
        return ret;
    }

    int bao(vector<vector<int>>& matrix, vector<int>& slt, int change)
    {
        if (change == slt.size()) {
            return Sum(matrix, slt);
        } else {
            int ret = 0;
            if (change > 0)
                slt[change] = slt[change - 1] + 1;
            for (int i = slt[change]; i < matrix[0].size() - slt.size() + change + 1; i++) {
                slt[change] = i;
                ret = max(ret, bao(matrix, slt, change + 1));
            }
            return ret;
        }
    }

    int maximumRows(vector<vector<int>>& matrix, int numSelect)
    {
        // 爆破
        vector<int> slt(numSelect, 0);
        for (int i = 0; i < numSelect; i++) {
            slt[i] = i;
        }
        return bao(matrix, slt, 0);
    }
};
// @lc code=end
