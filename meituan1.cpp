#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int n;
        cin >> n;
        vector<int> in_train(n);
        vector<int> out_train(n);
        for (int j = 0; j < n; j++)
        {
            cin >> in_train[j];
        }
        for (int j = 0; j < n; j++)
        {
            cin >> out_train[j];
        }
        // l表示in，r表示out;
        int l = 0;
        int r = 0;
        stack<int> sta;
        while (l < n && r < n)
        {
            if (sta.empty())
            {
                sta.push(in_train[l]);
                l++;
            }
            if (sta.top() == out_train[r])
            {
                sta.pop();
                r++;
            }
            else
            {
                if (l >= n)
                {
                    cout << "No" << endl;
                    break;
                }
                else
                {
                    sta.push(in_train[l]);
                    l++;
                }
            }
        }
        if (l == n && r == n)
            cout << "Yes" << endl;
        else
        {
            while (r < n)
            {
                if (sta.top() == out_train[r])
                {
                    sta.pop();
                    r++;
                }
                else
                {
                    cout << "No" << endl;
                    break;
                }
            }
            if (r == n)
                cout << "Yes" << endl;
        }
    }
    return 0;
}