/*
 * @lc app=leetcode.cn id=93 lang=cpp
这类题目的首先需要确定的是：
写出合格的判定；
然后写出不合格的判定
最后写出递归的算法
 * [93] 复原 IP 地址
 */

// @lc code=start
class Solution
{
public:
    vector<string> ans;
    void backtrace(string s, int index, int count, string str)
    {
        if (count == 4 && s.size() == index)
            ans.push_back(str.substr(0, str.size() - 1));
        if (count == 4 || s.size() == index)
            return;
        for (int i = 1; i <= 3; i++)
        {
            if (s.size() < index + i)
                return;
            if (s[index] == '0' && i != 1)
                return;
            if (i == 3 && s.substr(index, i) > "255")
                return;
            str += s.substr(index, i) + ".";
            backtrace(s, index + i, count + 1, str);
            str = str.substr(0, str.size() - i - 1);
        }
    }

    vector<string> restoreIpAddresses(string s)
    {
        string str = "";
        backtrace(s, 0, 0, str);
        return ans;
    }
};
// @lc code=end
