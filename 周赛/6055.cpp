#include "mylib.h"

class Solution
{
public:
    int convertTime(string current, string correct)
    {
        int t = stoi(correct.substr(0, 2)) * 60 - stoi(current.substr(0, 2)) * 60 + stoi(correct.substr(3, 5)) - stoi(current.substr(3, 5));
        int ans = 0;
        while (t > 0)
        {
            if (t / 60 > 0)
            {
                ans = ans + t / 60;
                t = t - 60 * (t / 60);
            }
            else if (t / 15 > 0)
            {
                ans = ans + t / 15;
                t = t - 15 * (t / 15);
            }
            else if (t / 5 > 0)
            {
                ans = ans + t / 5;
                t = t - 5 * (t / 5);
            }
            else
            {
                ans = ans + t / 1;
                t = t - t / 1;
            }
        }
        return ans;
    }
};

int main()
{
    Solution so;
    string current = "02:30";
    string correct = "04:35";
    cout << so.convertTime(current, correct);
    return 0;
}