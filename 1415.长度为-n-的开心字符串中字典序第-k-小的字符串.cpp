/*
 * @lc app=leetcode.cn id=1415 lang=cpp
 *
 * [1415] 长度为 n 的开心字符串中字典序第 k 小的字符串
 */

// @lc code=start
class Solution
{
public:
    string getHappyString(int n, int k)
    {
        int sum = 3 * pow(2, n - 1);
        string res;
        if (sum < k)
            return res;
        k = k - 1;
        sum = sum / 3;
        if (k / sum == 0)
            res += 'a';
        else if (k / sum == 1)
            res += 'b';
        else
            res += 'c';
        k = k % sum;
        n--;
        char s = res[res.size() - 1];
        while (n > 0)
        {
            sum = sum / 2;
            s = res[res.size() - 1];
            if (k / sum == 0)
            {
                if (s == 'a')
                    res += 'b';
                else
                    res += 'a';
            }
            else
            {
                if (s == 'c')
                    res += 'b';
                else
                    res += 'c';
            }
            k = k % sum;
            n--;
        }
        return res;
    }
};
// @lc code=end
