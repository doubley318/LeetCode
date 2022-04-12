/*
 * @lc app=leetcode.cn id=7 lang=cpp

int main()
{
    Solution so;
    // 3
    // int x = -2147483648;
    //int x = 1534236469;
    int x=123;
    cout << so.reverse(x) << endl;
    return 0;
}
 * [7] 整数反转
 */

// @lc code=start
class Solution
{
public:
    int reverse(int x)
    {
        int res = 0;
        int tmp = x;
        while (tmp != 0)
        {
            if (res > 214748364 || res < -214748364)
                return 0;
            res = res * 10 + tmp % 10;
            tmp = tmp / 10;
        }
        if ((x > 0 && res < 0) || (x < 0 && res > 0))
            return 0;
        return res;
    }
};
// @lc code=end
