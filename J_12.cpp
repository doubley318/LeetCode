#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    vector<vector<char>> myboard;
    int row, col;
    string myword;

public:
    bool myexist(int n, int m, int x)
    {
        if (x == myword.size())
            return true;
        if (n < 0 || m < 0 || n == row || m == col || myboard[n][m] != myword[x] || myboard[n][m] == '0')
            return false;
        char tmp = myboard[n][m];
        myboard[n][m] = '0';
        if (myexist(n - 1, m, x + 1) || myexist(n + 1, m, x + 1) || myexist(n, m + 1, x + 1) || myexist(n, m - 1, x + 1))
            return true;
        myboard[n][m] = tmp;
        return false;
    }
    bool exist(vector<vector<char>> &board, string word)
    {
        row = board.size();
        col = board[0].size();
        myword = word;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                myboard = board;
                if (myexist(i, j, 0))
                    return true;
            }
        }
        return false;
    }
};

int main()
{
    vector<vector<char>> word = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'E', 'S'}, {'A', 'D', 'E', 'E'}};
    Solution so;
    so.exist(word, "ABCESEEEFS");
    return 0;
}