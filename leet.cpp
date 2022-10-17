#include "mylib.h"

class Solution
{
public:
    int totalFruit(vector<int> &fruits)
    {
        int one = fruits[0], two = fruits[0];
        int loc_one = 0, loc_two = -1;
        int ret = 0, m = 0;
        for (int i = 0; i < fruits.size(); i++)
        {
            if (one != fruits[i] && two != fruits[i])
            {
                ret = max(ret, m);
                if (loc_one < loc_two)
                {
                    m = i - loc_one;
                    loc_one = i;
                    one = fruits[i];
                }
                else
                {
                    m = i - loc_two;
                    loc_two = i;
                    two = fruits[i];
                }
            }
            else
            {
                m++;
                if (one == fruits[i])
                    loc_one = i;
                else
                    loc_two = i;
            }
        }
        return max(ret, m);
    }
};

int main()
{
    Solution so;
    vector<int> fruits = {3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4};
    cout << so.totalFruit(fruits);
    return 0;
}