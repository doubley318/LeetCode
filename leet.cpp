#include "mylib.h"

class Codec
{
public:
    void dfs(vector<vector<char>> &board, int m, int n)
    {
        if (m < 0 || m >= board.size() || n < 0 || n >= board[0].size() || board[m][n] != 'O')
            return;
        board[m][n] = '#';
        dfs(board, m - 1, n);
        dfs(board, m + 1, n);
        dfs(board, m, n - 1);
        dfs(board, m, n + 1);
    }

    void solve(vector<vector<char>> &board)
    {
        int row = board.size();
        int col = board[0].size();
        for (int i = 0; i < col; i++)
            if (board[0][i] == 'O')
                dfs(board, 0, i);
        for (int i = 0; i < row; i++)
            if (board[i][col - 1] == 'O')
                dfs(board, i, row - 1);
        for (int i = 0; i < col; i--)
            if (board[row - 1][i] == 'O')
                dfs(board, row - 1, i);
        for (int i = 0; i < row; i++)
            if (board[i][0] == 'O')
                dfs(board, i, 0);
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == '#')
                    board[i][j] = 'O';
            }
        }
    }
};

int main()
{
    Codec co;

    return 0;
}