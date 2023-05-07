#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <set>
using namespace std;
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        vector<set<int>> totol_bag;
        vector<int> count_ball(n, 0);
        set<int> all_color;
        bool res = true;
        for (int i = 0; i < n; i++)
        {
            cin >> count_ball[i];
            // 一个袋子中球的颜色
            set<int> ball;
            for (int j = 0; j < count_ball[i]; j++)
            {
                int color;
                cin >> color;
                ball.insert(color);
                all_color.insert(color);
            }
            totol_bag.push_back(ball);
            // 1.判断两两是否相同
            if (count_ball[i] != ball.size())
                res = false;
        }
        // 2.判断袋子中球的数目是否相同
        if (res)
        {
            for (int i = 1; i < n; i++)
            {
                if (count_ball[i] != count_ball[i - 1])
                {
                    res = false;
                    break;
                }
            }
        }
        // 3.判断每一种颜色在袋子中的数量
        vector<int> diff_color;
        if (res)
        {
            for (auto color = all_color.begin(); res && color != all_color.end(); color++)
            {
                int times = 0;
                for (int i = 0; i < n; i++)
                {
                    if (totol_bag[i].find(*color) != totol_bag[i].end())
                    {
                        times++;
                    }
                }
                if (times == n)
                {
                    diff_color.push_back(*color);
                }
                else if (times != 1)
                {
                    res = false;
                }
            }
        }
        if (res == false)
        {
            cout << "No" << endl;
        }
        else
        {
            cout << "Yes";
            if (diff_color.size() != 0)
            {
                for (auto i : diff_color)
                {
                    cout << " " << i;
                }
            }
            cout << endl;
        }
    }
    return 0;
}