(n + 1, 1);
        int ret = INT_MAX;
        queue<int> que;
        que.push(1);
        while (!que.empty())
        {
            int tmp = que.front();
            for (int i = 0; i < m[tmp].size() / 2; i++)
            {
                if (dot[m[tmp][i * 2]] == 1)
                {
                    que.push(m[tmp][i * 2]);
                    ret = min(ret, m[tmp][i * 2 + 1]);
                }
            }
            dot[tmp] = 0;
            que.pop();
        }
        return ret;