#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

struct cmp
{
    bool operator()(char a, char b)
    {
        return a < b;
    }
};

int main()
{
    set<char> gao;
    set<char> zhong;
    set<char> di;
    string g = "bdfhkl";
    string z = "aceimnorstuvwxz";
    string d = "gjpqy";
    for (int i = 0; i < g.size(); i++)
    {
        gao.insert(g[i]);
    }
    for (int i = 0; i < z.size(); i++)
    {
        zhong.insert(z[i]);
    }
    for (int i = 0; i < d.size(); i++)
    {
        di.insert(d[i]);
    }
    string s;
    cin >> s;
    string my_gao;
    string my_zhong;
    string my_di;
    for (int i = 0; i < s.size(); i++)
    {
        if (gao.count(s[i]))
            my_gao.push_back(s[i]);
        else if (zhong.count(s[i]))
            my_zhong.push_back(s[i]);
        else
            my_di.push_back(s[i]);
    }
    sort(my_gao.begin(), my_gao.end());
    sort(my_zhong.begin(), my_zhong.end());
    sort(my_di.begin(), my_di.end());
    if (my_gao.empty())
        cout << "null" << endl;
    else
        cout << my_gao << endl;
    if (my_zhong.empty())
        cout << "null" << endl;
    else
        cout << my_zhong << endl;
    if (my_di.empty())
        cout << "null" << endl;
    else
        cout << my_di << endl;
    return 0;
}