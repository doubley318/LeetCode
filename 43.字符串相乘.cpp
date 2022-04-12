/*
 * @lc app=leetcode.cn id=43 lang=cpp
 *
 * [43] 字符串相乘
 */

// @lc code=start
class Solution {
public:
    string multiply(string num1, string num2)
    {
        map<char, string> multonum1;
        string ans;
        if (num1 == "0" || num2 == "0")
            return "0";
        int count = 0;
        for (int i = num2.size() - 1; i >= 0; i--)
        {
            if (multonum1.find(num2[i]) == multonum1.end())
            {
                string tmp;
                int jin = 0;
                for (int j = num1.size() - 1; j >= 0; j--)
                {
                    int a = (num1[j] - '0') * (num2[i] - '0') + jin;
                    jin = a / 10;
                    tmp = (char)(a % 10 + '0') + tmp;
                }
                if (jin != 0)
                    tmp = (char)(jin + '0') + tmp;
                multonum1.insert(pair<char, string>(num2[i], tmp));
            }
            string tmp;
            int jin = 0;
            auto j = multonum1.find(num2[i]);
            int k = ans.length() - 1 - count, l = j->second.size() - 1;
            while (k >= 0 || l >= 0)
            {
                char L, K;
                if (l >= 0)
                    L = j->second[l];
                else
                    L = '0';
                if (k >= 0)
                    K = ans[k];
                else
                    K = '0';
                if (K == '\00')
                    K = '0';
                int a = (L - '0') + (K - '0') + jin;
                jin = a / 10;
                tmp = (char)(a % 10 + '0') + tmp;
                l--;
                k--;
            }
            if (jin != 0)
                tmp = (char)(jin + '0') + tmp;
            ans = tmp + ans.substr(ans.length() - count, ans.size());
            count++;
        }
        return ans;
    }
};
// @lc code=end

