/*
 * @lc app=leetcode.cn id=12 lang=cpp
 *
 * [12] 整数转罗马数字
 */

// @lc code=start
class Solution
{
public:
    string intToRoman(int num)
    {
        string s;
        map<int, string> m = {{1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}};
        for (map<int,string>::reverse_iterator i=m.rbegin();i!=m.rend();i++)
        {
            if (num / i->first)
                for (int j = 0; j < num / i->first; j++)
                    s += i->second;
            num = num % i->first;
        }
        return s;
    }
};
// @lc code=end
