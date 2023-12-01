/*
 * @lc app=leetcode.cn id=1694 lang=cpp
 *
 * [1694] 重新格式化电话号码
 */

// @lc code=start
class Solution
{
public:
    string reformatNumber(string number)
    {
        string tmp = "";
        for (int i = 0; i < number.size(); i++)
            if (number[i] >= '0' && number[i] <= '9')
                tmp = tmp + number[i];
        string res = "";
        int len_number = tmp.size();
        int mark = 0;
        while (len_number > 4)
        {
            len_number -= 3;
            res = res + tmp.substr(mark, 3) + "-";
            mark += 3;
        }
        if (len_number <= 3)
            res = res + tmp.substr(mark, len_number);
        if (len_number == 4)
            res = res + tmp.substr(mark, 2) + "-" + tmp.substr(mark + 2, 2);
        return res;
    }
};
// @lc code=end
