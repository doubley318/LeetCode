/*
 * @lc app=leetcode.cn id=9 lang=cpp

int main()
{
    Solution so;
    int x = -121;
    cout << so.isPalindrome(x) << endl;
    return 0;
}
 * [9] 回文数
 */

// 11510/11510 cases passed (8 ms)
// Your runtime beats 77.26 % of cpp submissions
// Your memory usage beats 77.74 % of cpp submissions (5.8 MB)
//  @lc code=start
class Solution
{
public:
    bool isPalindrome(int x)
    {
        string s = to_string(x);
        for (int i = 0; i < s.size() / 2; i++)
        {
            if (s[i] != s[s.size() - 1 - i])
                return false;
        }
        return true;
    }
};
// @lc code=end
