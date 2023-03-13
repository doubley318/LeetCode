#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> mymap;
    int myk, row, col, res = 0;

    void mymoving(int m, int n)
    {
        if (m < 0 || n < 0 || m >= row || n >= col || mymap[m][n] == 1 || m % 10 + m / 10 + n % 10 + n / 10 > myk)
            return;
        mymap[m][n] = 1;
        res++;
        mymoving(m - 1, n);
        mymoving(m + 1, n);
        mymoving(m, n - 1);
        mymoving(m, n + 1);
    }

    int movingCount(int m, int n, int k)
    {
        myk = k;
        row = m;
        col = n;
        mymap = vector<vector<int>>(m, vector<int>(n, 0));
        mymoving(0, 0);
        return res;
    }
};

int main()
{
    int m = 2, n = 3, k = 1;
    Solution so;
    cout << so.movingCount(m, n, k);
    return 0;
}