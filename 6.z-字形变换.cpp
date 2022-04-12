/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
int main()
{
    Solution so;
    // 3
    string s = "PAYPALISHIRING";
    int a = 3;
    cout << so.convert(s, a) << endl;
    return 0;
}
 * [6] Z 字形变换
 */

// @lc code=start
/*
time:90%
memory:90%
class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1)
            return s;
        string res;
        int tmp = 0;
        int row = 0;
        int in_row = numRows - 1;
        int l = 1;
        for (int i = 0; i < s.size(); i++)
        {
            res += s[tmp];
            if (l == 1)
            {
                if (tmp + in_row * 2 >= s.size())
                {
                    row++;
                    in_row--;
                    tmp = row;
                    l = 1;
                }
                else
                {
                    if (in_row == 0)
                    {
                        if (tmp + row * 2 >= s.size())
                        {
                            row++;
                            in_row--;
                            tmp = row;
                        }
                        else
                            tmp += row * 2;
                    }
                    else
                        tmp += in_row * 2;
                    l = 0;
                }
            }
            else
            {
                if (tmp + row * 2 >= s.size())
                {
                    row++;
                    in_row--;
                    tmp = row;
                }
                else
                {
                    if (row == 0)
                    {
                        if (tmp + in_row * 2 >= s.size())
                        {
                            row++;
                            in_row--;
                            tmp = row;
                            l = 1;
                        }
                        else
                            tmp += in_row * 2;
                    }
                    else
                        tmp += row * 2;
                }
                l = 1;
            }
        }
        return res;
    }
};
*/
/*
Your runtime beats 77.52 % of cpp submissions
Your memory usage beats 27.51 % of cpp submissions (10.6 MB)
*/
class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1)
            return s;
        vector<string> res(numRows);
        int flag = 1;
        int row = 0;
        for (int i = 0; i < s.size(); i++)
        {
            res[row] += s[i];
            row += flag;
            if (row == numRows || row == -1)
            {
                row = row - 2 * flag;
                flag = 0 - flag;
            }
        }
        for (int i = 1; i < numRows; i++)
            res[0] += res[i];
        return res[0];
    }
};
// @lc code=end
