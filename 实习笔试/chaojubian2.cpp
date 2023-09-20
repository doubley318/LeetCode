#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

int main()
{
    string input;
    cin >> input;
    vector<string> strs;
    string tmp;
    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] != ',')
            tmp.push_back(input[i]);
        else
        {
            strs.push_back(tmp);
            tmp = "";
        }
    }
    strs.push_back(tmp);
    int k;
    cin >> k;
    int l = 0, r = 0;
    while (r < strs.size())
    {
        l = r;
        int tmp_len = strs[l].size();
        r++;
        int tmp_count = 0;
        while (tmp_len <= k && r < strs.size())
        {
            tmp_len += strs[r].size() + 1;
            r++;
            tmp_count++;
        }
        if (tmp_len > k)
        {
            r--;
            tmp_len = tmp_len - strs[r].size() - 1;
        }
        if (r == strs.size())
        {
            cout << strs[l];
            for (int i = l + 1; i < r; i++)
            {
                cout << "*" << strs[i];
            }
            for (int i = tmp_len; i < k; i++)
            {
                cout << "*";
            }
            cout << endl;
            break;
        }
        else
        {
            // tmp_count个缝
            tmp_count = tmp_count - 1;
            if (tmp_count == 0)
            {
                cout << strs[l];
                for (int i = tmp_len; i < k; i++)
                {
                    cout << "*";
                }
                cout << endl;
                continue;
            }
            // 剩下remain_len个**
            int remain_len = k - tmp_len + tmp_count;
            for (int i = l; i < r - 1; i++)
            {
                cout << strs[i];
                int x = ceil(1.0 * remain_len / tmp_count);
                for (int j = 0; j < x; j++)
                {
                    cout << "*";
                }
                remain_len -= x;
                tmp_count--;
            }
            cout << strs[r - 1] << endl;
        }
    }
    return 0;
}