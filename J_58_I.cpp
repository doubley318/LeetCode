#include <iostream>
#include <string>
using namespace std;
class Solution
{
public:
    string reverseWords(string s)
    {
        string res;
        int point = s.size() - 1;
        while (point >= 0)
        {
            while (point >= 0 && s[point] == ' ')
            {
                point--;
            }
            int tmp = point;
            while (point >= 0 && s[point] != ' ')
            {
                point--;
            }
            if (tmp != point)
                res = res + s.substr(point + 1, tmp - point) + " ";
        }
        return res.substr(0, res.size() - 1);
    }
};
int main()
{
    return 0;
}