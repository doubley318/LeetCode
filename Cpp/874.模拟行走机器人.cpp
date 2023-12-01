/*
 * @lc app=leetcode.cn id=874 lang=cpp
 *
 * [874] 模拟行走机器人
 */

// @lc code=start
class Solution
{
public:
    int robotSim(vector<int> &commands, vector<vector<int>> &obstacles)
    {
        unordered_set<int> tmp_set;
        for (auto i : obstacles)
        {
            tmp_set.insert(i[0] * 60001 + i[1]);
        }
        int ret = 0;
        int x = 0, y = 0, direction = 0;
        vector<vector<int>> my_direc = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        // north:0,east:1,south:2,west:3
        for (int i = 0; i < commands.size(); i++)
        {
            if (commands[i] < 0)
            {
                if (commands[i] == -1)
                    direction = (direction + 1) % 4;
                else if (commands[i] == -2)
                    direction = (direction + 3) % 4;
                continue;
            }
            while (commands[i] > 0)
            {
                --commands[i];
                x = x + my_direc[direction][0];
                y = y + my_direc[direction][1];
                if (tmp_set.find(x * 60001 + y) != tmp_set.end())
                {
                    x = x + my_direc[(direction + 2) % 4][0];
                    y = y + my_direc[(direction + 2) % 4][1];
                    break;
                }
                ret = max(ret, x * x + y * y);
            }
        }
        return ret;
    }
};
// @lc code=end
