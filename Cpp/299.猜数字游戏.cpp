/*
 * @lc app=leetcode.cn id=299 lang=cpp
 *
 * [299] 猜数字游戏
 */

// @lc code=start
class Solution
{
public:
    string getHint(string secret, string guess)
    {
        int A = 0, B = 0;
        vector<int> s(10, 0);
        vector<int> g(10, 0);
        for (int i = 0; i < secret.size(); i++)
        {
            if (secret[i] == guess[i])
                A++;
            else
            {
                s[secret[i] - '0']++;
                g[guess[i] - '0']++;
            }
        }
        for (int i = 0; i < 10; i++)
        {
            B = B + min(s[i],g[i]);
        }
        return to_string(A) + "A" + to_string(B) + "B";
    }
};
// @lc code=end
