/*
 * @lc app=leetcode.cn id=79 lang=cpp
超时！！！！！！！！！
class MinStack
{

public:
    bool exist(vector<vector<char>> &board, string word)
    {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                vector<vector<bool>> tmp(board.size(), vector<bool>(board[0].size()));
                if (matrix(board, word, i, j, tmp, 0) == true)
                    return true;
            }
        }
        return false;
    }

    bool matrix(vector<vector<char>> borad, string word, int row, int col, vector<vector<bool>> &tmp, int i)
    {
        if (word[i] != borad[row][col])
            return false;
        if (tmp[row][col] == true)
            return false;
        if (i == word.length() - 1)
            return true;
        tmp[row][col] = true;
        if (row > 0)
            if (matrix(borad, word, row - 1, col, tmp, i + 1) == true)
                return true;
        if (row + 1 < borad.size())
            if (matrix(borad, word, row + 1, col, tmp, i + 1) == true)
                return true;
        if (col > 0)
            if (matrix(borad, word, row, col - 1, tmp, i + 1) == true)
                return true;
        if (col + 1 < borad[0].size())
            if (matrix(borad, word, row, col + 1, tmp, i + 1) == true)
                return true;
        tmp[row][col] = false;
        return false;
    }
};
 * [79] 单词搜索
 */

// @lc code=start
class Solution
{
public:
    bool check(vector<vector<char>> &board, vector<vector<int>> &visited, int i, int j, string &s, int k)
    {
        if (board[i][j] != s[k])
        {
            return false;
        }
        else if (k == s.length() - 1)
        {
            return true;
        }
        visited[i][j] = true;
        vector<pair<int, int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        bool result = false;
        for (const auto &dir : directions)
        {
            int newi = i + dir.first, newj = j + dir.second;
            if (newi >= 0 && newi < board.size() && newj >= 0 && newj < board[0].size())
            {
                if (!visited[newi][newj])
                {
                    bool flag = check(board, visited, newi, newj, s, k + 1);
                    if (flag)
                    {
                        result = true;
                        break;
                    }
                }
            }
        }
        visited[i][j] = false;
        return result;
    }

    bool exist(vector<vector<char>> &board, string word)
    {
        int h = board.size(), w = board[0].size();
        vector<vector<int>> visited(h, vector<int>(w));
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                bool flag = check(board, visited, i, j, word, 0);
                if (flag)
                {
                    return true;
                }
            }
        }
        return false;
    }
};
// @lc code=end
