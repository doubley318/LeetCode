#include "mylib.h"

class Solution
{
public:
    string minimizeResult(string expression)
    {
        int ad;
        for (int i = 0; i < expression.length(); i++)
        {
            if (expression[i] == '+')
            {
                ad = i;
                break;
            }
        }
        string ans = "(" + expression + ")";
        int minnumber = INT_MAX;
        for (int i = 0; i < ad; i++)
        {
            int a1 = i == 0 ? 1 : stoi(expression.substr(0, i));
            int a2 = stoi(expression.substr(i, ad - i));
            for (int j = ad + 1; j < expression.length(); j++)
            {
                int b1 = stoi(expression.substr(ad + 1, expression.length() - j));
                int b2 = j == ad + 1 ? 1 : stoi(expression.substr(expression.length() - j + ad + 1, j - ad - 1));
                if (a1 * (a2 + b1) * b2 < minnumber)
                {
                    string e = expression;
                    ans = e.insert(i, "(");
                    ans = ans.insert(e.length() - j + ad + 1, ")");
                    minnumber = a1 * (a2 + b1) * b2;
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution so;
    string s = "12315+244522";
    cout << so.minimizeResult(s);
    return 0;
}