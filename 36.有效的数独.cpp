/*
 * @lc app=leetcode.cn id=36 lang=cpp
 *
 * [36] 有效的数独
 */

// @lc code=start
class Solution {
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        for (int i = 0; i < 9; i++)
        {
            int markr[10] = {0};
            int markc[10] = {0};
            int small[10] = {0};
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != '.' && markr[board[i][j] - '0'] == 0)
                    markr[board[i][j] - '0'] = 1;
                else if (board[i][j] != '.')
                    return false;
                if (board[j][i] != '.' && markc[board[j][i] - '0'] == 0)
                    markc[board[j][i] - '0'] = 1;
                else if (board[j][i] != '.')
                    return false;
                if (board[j / 3 + (i / 3) * 3][j % 3 + (i % 3) * 3] != '.' && small[board[j / 3 + (i / 3) * 3][j % 3 + (i % 3) * 3] - '0'] == 0)
                    small[board[j / 3 + (i / 3) * 3][j % 3 + (i % 3) * 3] - '0'] = 1;
                else if (board[j / 3 + (i / 3) * 3][j % 3 + (i % 3) * 3] != '.')
                    return false;
            }
        }
        return true;
    }
};
// @lc code=end

