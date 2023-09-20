#include <iostream>
#include <vector>
#include <queue>
using namespace std;
long long l;
long long r;
inline bool is_in_l_r(string s)
{
    long long tmp = 0;
    for (int i = 0; i < s.size(); i++)
    {
        tmp = (tmp << 1) + s[i] - '0';
        // cout << tmp << endl;
        if (tmp > r)
            return false;
    }
    if (tmp < l)
        return false;
    else
        return true;
}

int main()
{
    long long n;
    cin >> n >> l >> r;
    // 根本就不是树，而是图啦
    // 不会是动态规划吧，把从l-r的数字存起来。。。
    vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, 0));
    vector<int> value(n + 1);
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        value[i + 1] = s[i] - '0';
    }
    vector<vector<int>> tree(n + 1, vector<int>());
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    long long res = 0;
    for (int i = 1; i <= n; i++)
    {
        // 对每个节点进行宽度优先遍历
        vector<bool> doit(n + 1, false);
        doit[i] = true;
        queue<int> my_que;
        bool is_break = false;
        for (int j = 0; j < tree[i].size(); j++)
        {
            my_que.push(tree[i][j]);
            doit[tree[i][j]] = true;
            dp[i][tree[i][j]] = (value[i] << 1) + value[tree[i][j]];
            if (dp[i][tree[i][j]] > r)
            {
                is_break = true;
                break;
            }
            else if (dp[i][tree[i][j]] <= r && dp[i][tree[i][j]] >= l)
                res++;
        }
        // bfs
        while (!my_que.empty() && !is_break)
        {
            int tmp = my_que.size();
            for (int j = 0; j < tmp; j++)
            {
                // 看front的儿子们
                int f = my_que.front();
                for (int k = 0; k < tree[f].size(); k++)
                {
                    if (!doit[tree[f][k]])
                    {
                        dp[i][tree[f][k]] = (dp[i][f] << 1) + value[tree[f][k]];
                        doit[tree[f][k]] = true;
                        if (dp[i][tree[f][k]] > r)
                        {
                            break;
                        }
                        else if (dp[i][tree[f][k]] <= r && dp[i][tree[f][k]] >= l)
                            res++;
                        my_que.push(tree[f][k]);
                    }
                }
                my_que.pop();
            }
        }
    }
    cout << res;
    return 0;
}