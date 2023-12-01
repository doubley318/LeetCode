#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<string> findLongestSubarray(vector<string> &array)
    {
        int n = array.size();
        vector<vector<int>> table(n, vector<int>(2, 0));
        vector<vector<int>> tmp_res(0, vector<int>(2, 0));
        vector<string> res;
        int tmp_max=0;
        int l=0,r=0;
        for(int i=n-1;i>=0;i--)
        {
        }
        return res;
    }
};

int main()
{
    return 0;
}