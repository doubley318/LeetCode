/*
 * @lc app=leetcode.cn id=1349 lang=cpp
 *
 * [1349] 参加考试的最大学生数
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> set = { { 0, -1 }, { 0, 1 }, { 1, -1 }, { 1, 1 } };
    vector<vector<int>> dp;

    // 找下一个可以坐的地方
    vector<int> find(const vector<vector<char>>& seats, int i, int j)
    {
        for (; i < seats.size(); i++) {
            for (; j < seats[i].size(); j++) {
                if (seats[i][j] == '.') {
                    return { i, j };
                }
            }
            j = 0;
        }
        return {};
    }

    int function(vector<vector<char>>& seats, int i, int j)
    {
        int n = seats.size();
        int m = seats[0].size();
        vector<int> tmp(4, 0);
        // 两种选择，一种是坐人，一种是不坐
        int seatMan = 0, unseatMan = 0;
        {
            // 坐人
            for (int k = 0; k < set.size(); k++) {
                int x = set[k][0] + i;
                int y = set[k][1] + j;
                if (x >= 0 && x < n && y >= 0 && y < m) {
                    if (seats[x][y] == '.') {
                        // 表示不能坐人
                        seats[x][y] = 'x';
                        tmp[k] = 1;
                    }
                }
            }
            // 坐人了
            seats[i][j] = 'y';
            seatMan = 1;
            vector<int> nextLoc = find(seats, i, j);
            if (nextLoc.size() == 2) {
                if (dp[nextLoc[0]][nextLoc[1]] == -1) {
                    seatMan += function(seats, nextLoc[0], nextLoc[1]);
                } else {
                    seatMan += dp[nextLoc[0]][nextLoc[1]];
                }
            }
            // 还原
            seats[i][j] = '.';
            for (int k = 0; k < tmp.size(); k++) {
                if (tmp[k] == 1) {
                    seats[i + set[k][0]][j + set[k][1]] = '.';
                }
            }
        }
        {
            // 不坐人
            vector<int> nextLoc = find(seats, i, j + 1);
            if (nextLoc.size() == 2) {
                if (dp[nextLoc[0]][nextLoc[1]] == -1) {
                    unseatMan += function(seats, nextLoc[0], nextLoc[1]);
                } else {
                    unseatMan += dp[nextLoc[0]][nextLoc[1]];
                }
            }
        }
        dp[i][j] = max(seatMan, unseatMan);
        return dp[i][j];
    }

    int maxStudents(vector<vector<char>>& seats)
    {
        vector<int> nextLoc = find(seats, 0, 0);
        dp = vector<vector<int>>(seats.size(), vector<int>(seats[0].size(), -1));
        if (nextLoc.size() != 2) {
            return 0;
        } else {
            return function(seats, nextLoc[0], nextLoc[1]);
        }
    }
};
// @lc code=end
