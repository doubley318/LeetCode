#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> numstart(1000005, 0);
    vector<int> numend(1000005, 0);
    int max_end = 0, min_start = 1000005;
    while (n)
    {
        n--;
        int start, end;
        cin >> start;
        cin >> end;
        numstart[start]++;
        numend[end]--;
        max_end = max_end < end ? end : max_end;
        min_start = min_start > start ? start : min_start;
    }
    int res = 0;
    for (int i = min_start; i <= max_end; i++)
    {
        if (numstart[i] == 1)
            res += 3;
        else if (numstart[i] == 0)
            res += 1;
        else
            res += 4;
        numstart[i + 1] += numstart[i] + numend[i];
    }
    cout << res << endl;
    return 0;
}