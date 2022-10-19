/*
 * @lc app=leetcode.cn id=289 lang=cpp
 *
 * [289] 生命游戏
 */

// @lc code=start
class Solution
{
public:
    void gameOfLife(vector<vector<int>> &board)
    {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                // 每个细胞的操作
                // 3: 1->0, 2: 0->1
                int a = i - 1 > 0 ? i - 1 : 0;
                int b = j - 1 > 0 ? j - 1 : 0;
                int c = i + 1 < board.size() ? i + 1 : board.size() - 1;
                int d = j + 1 < board[0].size() ? j + 1 : board[0].size() - 1;
                int num = 0;
                for (int A = a; A <= c; A++)
                {
                    for (int B = b; B <= d; B++)
                    {
                        if ((A != i || B != j) && board[A][B] % 2 == 1)
                            num++;
                    }
                }
                if (num < 2 && board[i][j] % 2 == 1)
                    board[i][j] = 3;
                else if (num == 3 && board[i][j] % 2 == 0)
                    board[i][j] = 2;
                else if (num > 3 && board[i][j] % 2 == 1)
                    board[i][j] = 3;
            }
        }
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (board[i][j] == 3)
                    board[i][j] = 0;
                else if (board[i][j] == 2)
                    board[i][j] = 1;
            }
        }
    }
};
// @lc code=end
