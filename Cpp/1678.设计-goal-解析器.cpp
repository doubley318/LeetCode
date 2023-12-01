/*
 * @lc app=leetcode.cn id=1678 lang=cpp
 *
 * [1678] 设计 Goal 解析器
 */

// @lc code=start
class Solution
{
public:
    string interpret(string command)
    {
        string ret;
        for (int i = 0; i < command.size(); i++)
        {
            if (command[i] == 'G')
                ret = ret + "G";
            else if (command[i + 1] == 'a')
            {
                ret = ret + "al";
                i = i + 3;
            }
            else
            {
                ret = ret + "o";
                i = i + 1;
            }
        }
        return ret;
    }
};
// @lc code=end
