#include "mylib.h"

class Codec
{
public:
    int minDeletionSize(vector<string> &strs)
    {
        int ans = 0;
        for (int i = 0; i < strs[0].size(); i++)
        {
            char tmp = strs[0][i];
            for (int j = 1; j < strs.size(); j++)
            {
                if (tmp <= strs[j][i])
                {
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};

int main()
{
    Codec co;

    return 0;
}